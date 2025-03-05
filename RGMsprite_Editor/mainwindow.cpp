#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QVector>
#include <QShortcut>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(Model &model, QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    this->_model = &model;

    // setup the main graphics view
    _ui->graphicsViewCanvas->setScene(_canvas);
    _ui->graphicsViewCanvas->scene()->setSceneRect(_ui->graphicsViewCanvas->rect());  // scales the canvas to the QGraphicsView
    _ui->graphicsViewCanvas->setEnabled(true);

    QColorDialog *colorPicker1 = new QColorDialog();
    QColorDialog *colorPicker2 = new QColorDialog();
    colorPicker1->setOption(QColorDialog::ShowAlphaChannel, true);
    colorPicker2->setOption(QColorDialog::ShowAlphaChannel, true);

    // adds palette buttons to a list (ordered)
    for (int i = 0; i < _ui->paletteButtons->buttons().count(); i++)
    {
        QString name = QString("palette"+QString::number(i + 1));
        QToolButton *button = _ui->frameToolsAndPalette->findChild<QToolButton*>(name);
        _paletteHistory.append(QColor(255, 255, 255, 255));

        connect(button, &QToolButton::clicked, this, [=]()
                {
                    _canvas->setPrimaryColor(_paletteHistory.at(i));
                    _ui->color1Box->setStyleSheet(colorToString(_paletteHistory.at(i)));
                });

        _paletteButtons.append(button);
    }

    // Connects primary and secondary color boxes, palette history, and other color things
    connect(_ui->color1Box, &QToolButton::clicked, _canvas, [=](){ colorPicker1->show(); });
    connect(colorPicker1, &QColorDialog::colorSelected, _canvas, &Canvas::setPrimaryColor);
    connect(_ui->color2Box, &QToolButton::clicked, _canvas, [=](){ colorPicker2->show(); });
    connect(colorPicker2, &QColorDialog::colorSelected, _canvas, &Canvas::setSecondaryColor);
    connect(colorPicker1, &QColorDialog::colorSelected, _ui->color1Box, [=](QColor color)
            {
                QString newStyle = colorToString(color);
                _ui->color1Box->setStyleSheet(newStyle);
                if (_paletteHistory.size() == _ui->paletteButtons->buttons().count()) _paletteHistory.replace(_paletteHistoryIndex, color);
                else _paletteHistory.insert(_paletteHistoryIndex, color);
                updatePaletteHistory();
            });

    connect(colorPicker2, &QColorDialog::colorSelected, _ui->color2Box, [=](QColor color)
            {
                QString newStyle = colorToString(color);
                _ui->color2Box->setStyleSheet(newStyle);
                if (_paletteHistory.size() == _ui->paletteButtons->buttons().count()) _paletteHistory.replace(_paletteHistoryIndex, color);
                else _paletteHistory.insert(_paletteHistoryIndex, color);
                updatePaletteHistory();
            });

    connect(_ui->swapColors, &QToolButton::clicked, this, [=]()
            {
                QString temp = _ui->color1Box->styleSheet();
                _ui->color1Box->setStyleSheet(_ui->color2Box->styleSheet());
                _ui->color2Box->setStyleSheet(temp);
                _canvas->swapColors();
            });

    // Connects the toolButtons
    connect(_ui->penToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(PenTool); });
    connect(_ui->mirrorPenToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(MirrorPenTool); });
    connect(_ui->eraserToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(EraserTool); });
    connect(_ui->ditheringPenToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(DitheringTool); });
    connect(_ui->rectangleToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(RectangleTool); });
    connect(_ui->bucketPenToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(BucketFillTool); });
    connect(_ui->colorFillToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(ColorFillTool); });
    connect(_ui->ellipseToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(EllipseTool); });
    connect(_ui->rectangularSelectionToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(RectSelectTool); });
    connect(_ui->lineToolButton, &QToolButton::clicked, _canvas, [=](){ _canvas->setTool(LineTool); });

    // Connects the undo/redo actions
    connect(_ui->actionUndo, &QAction::triggered, &model, &Model::undo);
    connect(_ui->actionRedo, &QAction::triggered, &model, &Model::redo);
    //connect(_canvas, &Canvas::pixelsModified, &model, &Model::updateUndoRedo);
    connect(_canvas, &Canvas::updateUndo, &model, &Model::updateUndoRedo);
    connect(&model, &Model::frameUpdated, _canvas, &Canvas::setFrame);

    // Connects the File>New actions
    connect(_ui->action8x8, &QAction::triggered, this, [=](){ newCanvas(8); });
    connect(_ui->action16x16, &QAction::triggered, this, [=](){ newCanvas(16); });
    connect(_ui->action32x32, &QAction::triggered, this, [=](){ newCanvas(32); });
    connect(_ui->action64x64, &QAction::triggered, this, [=](){ newCanvas(64); });

    // Connects the drawing surfaces (main drawing area, preview area, FPS, etc.)
    connect(_ui->spinBoxSpeed, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &model, &Model::setPreviewFPS);
    connect(&model, &Model::frameUpdated, _canvas, &Canvas::setFrame);
    connect(&model, &Model::previewFrame, this, [=](QImage image) {
        if (_ui->zoomLevelCheckbox->isChecked())
        {
            _ui->labelPreview->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            _ui->labelPreview->setPixmap(QPixmap::fromImage(image).scaled(_ui->labelPreview->size()));
        }
    });

    connect(_ui->zoomLevelCheckbox, &QCheckBox::toggled, this, [=](bool toggled){
        if (toggled)
        {
            QSize oneToOne = QSize(_ui->labelPreview->objectName().toInt(), _ui->labelPreview->objectName().toInt());
            _ui->labelPreview->setPixmap(_ui->labelPreview->pixmap()->scaled(oneToOne));
        }
        else
        {
            _ui->labelPreview->setPixmap(_ui->labelPreview->pixmap()->scaled(_ui->labelPreview->size()));
        }
    });

    connect(_canvas, &Canvas::frameUpdated, this, [=](Frame *frame)
            {
                QLabel *l = _frameButtons.checkedButton()->parent()->findChild<QLabel *>("view");
                l->setPixmap(QPixmap::fromImage(frame->pixels().scaled(l->size())));
            });

    // connects the File>Export actions
    connect(_ui->actionCurrentFrame, &QAction::triggered, this, [=]()
            {
                QString filename = QFileDialog::getSaveFileName(this, "Export to .PNG", "./", "PNG Files (*.png)");
                this->_model->saveFrameToPNG(filename);
            });
    connect(_ui->actionAll_Frames, &QAction::triggered, this, [=]()
            {
                QString dirname = QFileDialog::getExistingDirectory(this, "Export frames to directory.", "./");
                this->_model->saveFrameSequence(dirname);
            });
    connect(_ui->actionSprite_Sheet, &QAction::triggered, this, [=]()
            {
                QString filename = QFileDialog::getSaveFileName(this, "Export frames to PNG spritesheet.", "./", "PNG Files (*.png)");
                this->_model->saveSpriteSheet(filename);
            });
    connect(_ui->actionAnimated_GIF, &QAction::triggered, &model, [=]()
            {
                QString filename = QFileDialog::getSaveFileName(this, "Export to animated .GIF", "./", "GIF Files (*.gif)");
                this->_model->saveAnimatedGIF(filename);
            });

    // connects the File>Exit action
    connect(_ui->actionExit, &QAction::triggered, &model, &Model::exit);

    connect(_ui->pushButtonAddFrame, &QPushButton::clicked, &model, &Model::createFrame);
    connect(&model, &Model::frameCreated, this, [=](int i){ newFrame(i); });

    //	connects File>Save and >Load
    connect(this, &MainWindow::checkSave, &model, &Model::checkSaveStatus);
    connect(_ui->actionSave, &QAction::triggered, this, [=]()
            {
                QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::currentPath(), tr("Sprites (*.ssp)"));
                this->_model->saveToFile(filename);
            });
    connect(_ui->actionLoad, &QAction::triggered, this, [=]()
            {
                //need to check whether to save first.
                emit checkSave();
                QString filename = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath(), tr("Sprites (*.ssp)"));
                if(!filename.isEmpty() && !filename.isNull())
                {
                    this->_model->loadFromFile(filename);
                }
            });
    connect(&model, &Model::savePrompt, this, &MainWindow::saveDialog);

    // Connects the Shortcut Keys
    _ui->penToolButton->setShortcut(Qt::CTRL | Qt::Key_1);

    //Helper connections for loading a file
    connect(&model, &Model::newCanvasSignal, this, &MainWindow::newCanvasSlot);

    model.newSurface(32);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

//Converts a given QColor to a QString based on its RGB values
QString MainWindow::colorToString(QColor color)
{
    return "background-color: rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ");";
}

//Updates the color history
void MainWindow::updatePaletteHistory()
{
    QString newStyle;
    newStyle = colorToString(_paletteHistory.at(_paletteHistoryIndex));
    _paletteButtons.at(_paletteHistoryIndex)->setStyleSheet(newStyle);
    _paletteHistoryIndex++;

    if (_paletteHistoryIndex == _ui->paletteButtons->buttons().count())
    {
        _paletteHistoryIndex = 0;
    }
}

//Prompts user to save if they are about to discard unsaved changes
void MainWindow::saveDialog(){
    QMessageBox saveBox;
    saveBox.setText("The sprite has been modified.");
    saveBox.setInformativeText("Do you want to save your changes?");
    saveBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    saveBox.setDefaultButton(QMessageBox::Save);
    int result = saveBox.exec();
    switch (result)
    {
    case QMessageBox::Save:
        //Tell model to save.
        emit _ui->actionSave->triggered();
        break;
    case QMessageBox::Discard:
        //Do nothing so that the process can continue
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked. Not sure how to implement this option.
        break;
    default:
        break;
    }
}

//Helper method for loading. Used to create a new canvas from scratch before drawing in saved pixels
void MainWindow::newCanvasSlot(int dimension)
{
    newCanvas(dimension);
}

//Creates a new cavnas upon user request
void MainWindow::newCanvas(int dimension)
{
    emit checkSave();
    emit resetCanvas();
    this->disconnect();
    _model->newSurface(dimension);
    connect(this, &MainWindow::checkSave, _model, &Model::checkSaveStatus);
}

//Creates a new frame and adds it to the frame selection and preview
void MainWindow::newFrame(int index)
{
    QFrame *newFrame = new QFrame();
    newFrame->setGeometry(0, 0, 75, 75);
    newFrame->setMinimumWidth(75);
    newFrame->setMinimumHeight(75);
    newFrame->setMaximumWidth(75);
    newFrame->setMaximumHeight(75);

    connect(this, &MainWindow::resetCanvas, this, [=]()
            {
                newFrame->hide();
                _ui->frameContainer->layout()->removeWidget(newFrame);
                newFrame->setParent(nullptr);
                delete newFrame;
            });

    QLabel *framePreview = new QLabel();
    framePreview->setGeometry(0, 0, 75, 75);
    framePreview->setObjectName("view");
    framePreview->setMinimumWidth(75);
    framePreview->setMinimumHeight(75);
    framePreview->setMaximumWidth(75);
    framePreview->setMaximumHeight(75);
    framePreview->setAttribute(Qt::WA_TransparentForMouseEvents);

    QPushButton *frameSelected = new QPushButton(newFrame);
    frameSelected->setGeometry(0, 0, 75, 75);
    frameSelected->setObjectName("button");
    frameSelected->setCheckable(true);
    _frameButtons.addButton(frameSelected, index);
    connect(frameSelected, &QPushButton::clicked, _model, [=]()
            {
                int frameNum = _ui->frameContainer->layout()->indexOf(newFrame);
                _model->setActiveFrame(frameNum);
            });
    framePreview->setParent(newFrame);

    QToolButton *dupeFrame = new QToolButton(newFrame);
    dupeFrame->setGeometry(60, 60, 15, 15);
    dupeFrame->setObjectName("dupe");
    dupeFrame->setText("D");
    connect(dupeFrame, &QToolButton::clicked, _model, [=]()
            {
                int frameNum = _ui->frameContainer->layout()->indexOf(newFrame);
                frameSelected->setChecked(true);
                _model->setActiveFrame(frameNum);
                _model->dupeFrame(frameNum);
            });

    QToolButton *removeFrame = new QToolButton(newFrame);
    removeFrame->setGeometry(0, 0, 15, 15);
    removeFrame->setObjectName("remove");
    removeFrame->setText("X");
    connect(removeFrame, &QToolButton::clicked, _model, [=]()
            {
                QLayout *framesLayout = _ui->frameContainer->layout();
                int frameNum = framesLayout->indexOf(newFrame);
                frameSelected->setChecked(true);
                _model->setActiveFrame(frameNum);
                _model->deleteFrame(frameNum);

                if (framesLayout->parent()->children().count() > 2)
                {
                    if (frameNum > 0 && frameNum < framesLayout->parent()->children().count() - 2)
                    {
                        frameNum += 1;
                    }
                    else if (frameNum != 0)
                    {
                        frameNum -= 1;
                    }
                    framesLayout->itemAt(frameNum)->widget()->findChild<QPushButton *>("button")->setChecked(true);
                    newFrame->hide();
                    framesLayout->removeWidget(newFrame);
                    newFrame->setParent(nullptr);
                    delete newFrame;
                    if (_frameButtons.checkedButton() == nullptr)
                    {
                        framesLayout->itemAt(frameNum)->widget()->findChild<QPushButton *>("button")->setChecked(true);
                    }
                }
            });


    // remove the spacer
    _ui->frameContainer->layout()->removeItem(_ui->frameContainer->layout()->itemAt(_ui->frameContainer->layout()->count()-1));

    // add the newFrame
    _ui->frameContainer->findChild<QHBoxLayout *>("horizontalLayout")->insertWidget(index, newFrame);
    newFrame->findChild<QPushButton *>("button")->setChecked(true);

    // re-add a horizontal spacer
    _ui->frameContainer->layout()->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding));
}


//MainWindow::~MainWindow()
//{
//    delete _ui;
//}

//void MainWindow::closeEvent(QCloseEvent *event)
//{/

//}

//void MainWindow::open()
//{

//}

//void MainWindow::save()
//{

//}

//void MainWindow::penColor()
//{

//}

//void MainWindow::penWidth()
//{

//}

//void MainWindow::about()
//{

//}
