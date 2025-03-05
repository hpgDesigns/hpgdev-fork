#include "model.h"
#include <gif.h>


Model::Model(QObject *parent) : QObject(parent)
{
    _previewAnimTimer.setInterval(1000/12);
    connect(&_previewAnimTimer, &QTimer::timeout, this, &Model::previewDisplay);
    _previewAnimTimer.start();

}

// Called every tick of a timer to update the preview area display
void Model::previewDisplay(){
    emit previewFrame(_frames.at(_previewAnimIndex)->pixels());
    if(_previewAnimIndex + 1 == _frames.size())
    {
        _previewAnimIndex = 0;
    }
    else
    {
        _previewAnimIndex++;
    }
}

// Sets the FPS of the preview area display
void Model::setPreviewFPS(int secs) {
    _previewAnimTimer.setInterval(1000/secs);
}

// Sets the current frame being worked/drawn upon
void Model::setActiveFrame(int index) {
    _currentFrame = _frames.at(index);
    emit frameUpdated(_currentFrame);
}

// Creates a new surface; clears everything and starts a new surface
void Model::newSurface(int dimension) {
    _previewAnimTimer.stop();

    Frame *newFrame = new Frame(dimension);
    clearFrames();
    _frames.append(newFrame);
    _currentFrame = newFrame;
    emit frameCreated(_frames.indexOf(_currentFrame));
    emit frameUpdated(_currentFrame);
    _isSaved = true;

    _previewAnimIndex = 0;
    _previewAnimTimer.start(_previewAnimTimer.interval());
}

// Creates a frame right after the currently active frame
//   and makes the newly creative frame the currently active frame
void Model::createFrame() {
    Frame *newFrame = new Frame(_frames.first()->size().width());
    _frames.insert(_frames.indexOf(_currentFrame)+1, newFrame);
    _currentFrame = newFrame;
    emit frameCreated(_frames.indexOf(_currentFrame));
    emit frameUpdated(_currentFrame);
    _isSaved = false;
}

// Duplicate the frame at a given index and set the duplicate
//   as the currently active frame
void Model::dupeFrame(int index) {
    Frame *newFrame = new Frame(*_frames.at(index));
    _frames.insert(_frames.indexOf(_currentFrame)+1, newFrame);
    _currentFrame = newFrame;
    emit frameCreated(_frames.indexOf(_currentFrame));
    emit frameUpdated(_currentFrame);
    _isSaved = false;
}

// Delete the frame at a given index
void Model::deleteFrame(int index) {
    _previewAnimTimer.stop();

    if (index > 0 && index < _frames.size() - 1)
    {
        _frames.removeAt(index);
        _currentFrame = _frames.at(index);
    }
    else if (index == 0)
    {
        int dimen = _frames.first()->size().width();
        _frames.removeFirst();
        if (_frames.size() == 0)
        {
            newSurface(dimen);
        }
        else
        {
            _currentFrame = _frames.at(index);
        }
    }
    else
    {
        _frames.removeAt(index);
        _currentFrame = _frames.at(index - 1);
    }
    emit frameUpdated(_currentFrame);
    _isSaved = false;

    _previewAnimIndex = 0;
    _previewAnimTimer.start(_previewAnimTimer.interval());
}

// When a new change is made we push image into undoStack and clear redoStack
void Model::updateUndoRedo(QImage newImage) {
    _isSaved = false;
    _currentFrame->updateUndoRedo(newImage);
}

// Tells the currentframe to run an undo command.
void Model::undo() {
    _currentFrame->undo();
    emit frameUpdated(_currentFrame);
}

// Tells the current frame to run a redo command.
void Model::redo() {
    _currentFrame->redo();
    emit frameUpdated(_currentFrame);
}

// So, gif.h ignores transparency unless we use GifWriteFrame8.
// However, I can not seem to get that to work.  If someone else wants to try, feel free.
void Model::saveAnimatedGIF(QString filename) {
    int frameWidth = _frames.first()->pixels().width();
    int frameHeight = _frames.first()->pixels().height();

    GifWriter *writer = new GifWriter();
    GifBegin(writer, fopen(filename.toLatin1().constData(), "w"), frameWidth, frameHeight, _previewAnimTimer.interval(), true);
    QImage img;
    for (int i = 0; i < _frames.size(); i++)
    {
        img = _frames.at(i)->pixels();
        uint8_t *bitsArr = img.bits();
        int index = 0;
        while (index < frameWidth * frameHeight * 4)
        {
            // Since gif.h ignores transparency, just make transparent pixels white
            if (bitsArr[index+3] == 0)
            {
                bitsArr[index++] = 255;
                bitsArr[index++] = 255;
                bitsArr[index++] = 255;
                bitsArr[index++] = 255;
            }
            else
            {
                index += 4;
            }
        }
        GifWriteFrame(writer, bitsArr, frameWidth, frameHeight, _previewAnimTimer.interval() / 10);
        //        GifWriteFrame8(writer, bitsArr, frameWidth, frameHeight, _previewAnimTimer.interval() / 10);
    }
    GifEnd(writer);
}

// Save the currently active frame to a PNG
void Model::saveFrameToPNG(QString filename) {
    if (!filename.toLower().endsWith(".png"))
    {
        filename.append(".png");
    }
    _currentFrame->pixels().save(filename);
}

// Save the frames as a sequence of PNG images
// E.g. 3 frames get saved to 'dir' with the names: frame_1.png, frame_2.png, frame_3.png
void Model::saveFrameSequence(QString dir) {

    // Create the directory if it does not exist.
    if (!QDir(dir).exists())
    {
        QDir().mkdir(dir);
    }

    // Save a PNG to the directory for each frame.
    QString filename;
    for (int i = 0; i < _frames.count(); i++)
    {
        filename = dir + QDir::separator() + "frame_" + QString::number(i) + ".png";
        _frames.at(i)->pixels().save(filename);
    }
}

// Saves all the frames to a (somewhat) traditional style sprite sheet.
void Model::saveSpriteSheet(QString filename) {
    if (!filename.toLower().endsWith(".png"))
    {
        filename.append(".png");
    }

    QSize spriteSize = _frames.first()->pixels().size();

    // The ceil floor is to try to limit the amount of blank space in the resulting image.
    int width = ceil(sqrt(_frames.count()));
    int height = ceil(sqrt(_frames.count()));
    QImage sheet = QImage(QSize(width * spriteSize.width(), height * spriteSize.height()), QImage::Format_ARGB32);

    // Gets rid of image artifacts that are present on creation for some reason.
    sheet.fill(QColor(0, 0, 0, 0));

    int frameIndex = 0;
    QPainter *painter = new QPainter(&sheet);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Stop trying to add frames to the image if none are left.
            if (frameIndex >= _frames.count())
            {
                break;
            }

            // Add the frame to the sprite sheet
            painter->drawImage(x * spriteSize.width(), y * spriteSize.height(), _frames.at(frameIndex++)->pixels());
        }
    }
    painter->end();

    // Save the sprite sheet.
    sheet.save(filename);
}

// Save the frames to a project file.  The format was specified in the assignment
//   specifications page
void Model::saveToFile(QString filename)
{
    if (!filename.toLower().endsWith(".ssp"))
    {
        filename.append(".ssp");
    }

    QFile file(filename);
    file.open(QFile::WriteOnly);
    QTextStream outstream(&file);

    int sizeX = _currentFrame->size().rwidth();
    int sizeY = _currentFrame->size().rheight();
    outstream << sizeX << " " << sizeY << Qt::endl; //prints x and y dimensions

    outstream << _frames.size() << Qt::endl; //prints number of frames

    for (int i = 0; i < _frames.size(); i++)
    {
        QImage frame = _frames.at(i)->pixels();

        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                QRgb pixel = frame.pixel(x, y);
                outstream << qRed(pixel) << " " << qGreen(pixel) << " " << qBlue(pixel) << " " << qAlpha(pixel) << " ";
            }
            outstream << Qt::endl;
        }
    }
    file.close();
    _isSaved = true;
}

// Load from a project file
void Model::loadFromFile(QString filename)
{
    _previewAnimTimer.stop();

    if (filename.length() < 4)
    {
        return;
    }

    QFile f(filename);
    f.open(QIODevice::ReadOnly);
    QTextStream in(&f);

    QList<int> list;
    while (!in.atEnd())
    {
        int x;
        in >> x;
        list.append(x);
    }

    int sizeX = list.at(0);
    int sizeY = list.at(1);
    int frames = list.at(2);

    //accounts for loading non-square sprites
    if (sizeX > sizeY)
    {
        emit newCanvasSignal(sizeX);
    }
    else
    {
        emit newCanvasSignal(sizeY);
    }

    int listIter = 3;
    for (int f = 1; f <= frames; f++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                //reads in the next 4 values and creates a color
                QColor color;
                color.setRed(list.at(listIter++));
                color.setGreen(list.at(listIter++));
                color.setBlue(list.at(listIter++));
                color.setAlpha(list.at(listIter++));
                _currentFrame->drawPen(QPoint(x, y), color);
            }
        }

        emit frameUpdated(_currentFrame);

        //if necessary creates a new frame
        if (f < frames)
        {
            createFrame();
        }
    }

    f.close();

    _previewAnimTimer.start();
}

// If not saved, signal for a save prompt
void Model::checkSaveStatus()
{
    if (!_isSaved)
    {
        emit savePrompt();
    }
}

// Clear the frames and mark as unsaved
void Model::clearFrames() {
    _frames.clear();
    _isSaved = false;
}

// A slot called when exit (from the menu) is requested
void Model::exit() {
    if (!_isSaved)
    {
        emit savePrompt();
        QApplication::quit();
    }
    else
    {
        //So that the user can quit a saved project.
        QApplication::quit();
    }
}
