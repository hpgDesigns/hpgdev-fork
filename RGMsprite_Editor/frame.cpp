#include "frame.h"

Frame::Frame() {}

//Copy constructor.
Frame::Frame(Frame& f)
{
    this->_image = f._image;
    this->_undoStack = f._undoStack;
    this->_redoStack = f._redoStack;
    _painter = new QPainter(&_image);
}

//Creates a frame of the given square dimension.
Frame::Frame(int dimension)
{
    _image = QImage(dimension, dimension, QImage::Format_ARGB32);
    _image.fill(QColor(0, 0, 0, 0));  // gets rid of weird artifacts that appear on creation
    _undoStack.push(_image);
    _painter = new QPainter(&_image);
    _painter->setBackgroundMode(Qt::TransparentMode);
    _dimension = dimension;
}

//Destructor.
Frame::~Frame()
{
    _painter->end();
    _undoStack.clear();
    _redoStack.clear();
    _pixelStack.clear();
}

//Draws an ellipse on the frame.
void Frame::drawEllipse(QRect area, QColor line, QColor fill)
{
    setupDraw(line, fill, _tempImage,_tempImage.rect());
    _painter->setBrush(fill);
    _painter->drawEllipse(area);
}

//Draws like the pen tool except also mirrors the operation across the y-axis.
void Frame::drawMirrorPen(QPoint point, QColor color)
{
    _painter->setPen(color);
    _painter->setBrush(QColor(0, 0, 0, 0));
    _painter->drawPoint(point);
    _painter->drawPoint(-point.x() + _image.size().width() - 1, point.y());
}

//Pen tool enables freeform drawing on the frame in a single color.
void Frame::drawPen(QPoint point, QColor color)
{
    _painter->setPen(color);
    _painter->setBrush(QColor(0, 0, 0, 0));
    _painter->drawPoint(point);
}

//Helper function for drawing rectangles and selecting pixel tools.
void Frame::setupDraw(QColor line, QColor fill, QImage temp, QRect area)
{
    QColor tempColor(0,0,0,0);
    QBrush tempBrush(tempColor);
    _image.fill(tempColor);
    QImage _image(temp);
    _painter->drawImage(_image.rect(), _image, area, Qt::AutoColor);
    _painter->setPen(line);
}

//Draws a rectangle on the frame.
void Frame::drawRectangle(QRect area, QColor line, QColor fill)
{
    setupDraw(line, fill, _tempImage, _tempImage.rect());
    _painter->setBrush(fill);
    _painter->drawRect(area);
}

//Draws a line between two points and fills it in with the passed in color.
void Frame::drawLine(QPoint start, QPoint end, QColor color)
{
    _painter->setPen(color);
    _painter->setBrush(QColor(0, 0, 0, 0));
    _image.fill(QColor(0,0,0,0));
    QImage _image(_tempImage);
    _painter->drawImage(_image.rect(), _image, _tempImage.rect(), Qt::AutoColor);
    _painter->drawLine(start, end);
}

//Erases a pixel by changing its color to transparent.
void Frame::erase(QPoint point)
{
    _image.setPixelColor(point, QColor(0, 0, 0, 0));
}

//The bucket fill tool replaces one color in a closed space with another color.
//We run the function recursively checking the 4 cardinal directions from each pixel.
void Frame::bucketFill(QPoint startPoint, QColor initialColor, QColor replacementColor)
{
    // Fill behavior is undefined if you click the same color as you want to fill so we do nothing.
    if(initialColor == replacementColor)
    {
        return;
    }
    if(_image.pixelColor(startPoint) != initialColor)
    {
        return;
    }
    _image.setPixelColor(startPoint, replacementColor);
    //We recursively look in cardinal directions (up, down, left, right).
    if(startPoint.y()+1 < size().height())
    {
        bucketFill(QPoint(startPoint.x(), startPoint.y()+1), initialColor, replacementColor);
    }
    if(startPoint.y()-1 >= 0)
    {
        bucketFill(QPoint(startPoint.x(), startPoint.y()-1), initialColor, replacementColor);
    }
    if(startPoint.x()-1 >= 0)
    {
        bucketFill(QPoint(startPoint.x()-1, startPoint.y()), initialColor, replacementColor);
    }
    if(startPoint.x()+1 < size().width())
    {
        bucketFill(QPoint(startPoint.x()+1, startPoint.y()), initialColor, replacementColor);
    }
}

// This is the color-fill tool.  We might want to rename it to better reflect that.
void Frame::colorSwap(QPoint startPoint, QColor color)
{
    QColor oldColor = _image.pixelColor(startPoint);
    // the below link really helped here
    // https://forum.qt.io/topic/32039/pixmap-mask-not-coloring-over-the-image/2
    QBitmap mask = QPixmap::fromImage(_image).createMaskFromColor(oldColor.rgb(), Qt::MaskOutColor);
    _painter->setPen(color);
    _painter->drawPixmap(_image.rect(), mask, mask.rect());
}

//Selects pixels in the drawn region.
void Frame::selectRegion(QRect area, QColor line, QColor fill)
{
    setupDraw(line, fill, _prevSelectionToolImage, _prevSelectionToolImage.rect());
    _painter->setBrush(fill);
    _painter->drawRect(area);
}

//Pops an older version of the image off the undoStack and replaces the current image.
void Frame::undo()
{
    if (!_undoStack.isEmpty())
    {
        _redoStack.push(_image);
        _tempImage = _undoStack.pop();
        _painter->end();
        _image = _tempImage;
        _painter->begin(& _image);
    }
}

//Pops a newer version of the frame image off the redoStack and replaces the current image.
void Frame::redo()
{
    if (!_redoStack.isEmpty())
    {
        _undoStack.push(_image);
        _tempImage = _redoStack.pop();
        _painter->end();
        _image = _tempImage;
        _painter->begin(& _image);
    }
}

//Called when a new change is made to the image.
//Resets the redoStack and adds the current image to the undoStack.
void Frame::updateUndoRedo(QImage newImage)
{
    if(_blankFrame)
    {
        _blankFrame = false;
        return;
    }
    if (!_redoStack.isEmpty())
    {
        _redoStack = QStack<QImage>();
    }
    _undoStack.push(newImage);
}

//Gets the current image in a QImage format.
QImage Frame::pixels()
{
    return _image;
}

//Gets the size of the current image in pixels.
QSize Frame::size()
{
    return _image.size();
}
