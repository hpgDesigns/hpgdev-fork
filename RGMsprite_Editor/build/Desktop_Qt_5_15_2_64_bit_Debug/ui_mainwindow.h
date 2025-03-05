/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *action8x8;
    QAction *action16x16;
    QAction *action32x32;
    QAction *action64x64;
    QAction *actionAnimated_GIF;
    QAction *actionCurrentFrame;
    QAction *actionAll_Frames;
    QAction *actionSprite_Sheet;
    QWidget *centralwidget;
    QFrame *framePreview;
    QSpinBox *spinBoxSpeed;
    QLabel *labelSpeed;
    QLabel *labelPreview;
    QCheckBox *zoomLevelCheckbox;
    QFrame *frameToolsAndPalette;
    QToolButton *eraserToolButton;
    QToolButton *mirrorPenToolButton;
    QToolButton *ditheringPenToolButton;
    QToolButton *colorFillToolButton;
    QToolButton *bucketPenToolButton;
    QToolButton *ellipseToolButton;
    QToolButton *rectangleToolButton;
    QToolButton *color1Box;
    QToolButton *penToolButton;
    QToolButton *color2Box;
    QToolButton *rectangularSelectionToolButton;
    QToolButton *lineToolButton;
    QToolButton *palette1;
    QToolButton *palette2;
    QToolButton *palette3;
    QToolButton *palette4;
    QToolButton *palette7;
    QToolButton *palette5;
    QToolButton *palette6;
    QToolButton *palette8;
    QToolButton *palette11;
    QToolButton *palette9;
    QToolButton *palette10;
    QToolButton *palette12;
    QToolButton *palette15;
    QToolButton *palette16;
    QToolButton *palette13;
    QToolButton *palette14;
    QToolButton *swapColors;
    QGraphicsView *graphicsViewCanvas;
    QScrollArea *scrollAreaFrameContainer;
    QWidget *frameContainer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonAddFrame;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuExport;
    QMenu *menuEDit;
    QStatusBar *statusbar;
    QToolBar *mainToolBar;
    QButtonGroup *toolButtons;
    QButtonGroup *paletteButtons;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(690, 767);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        action8x8 = new QAction(MainWindow);
        action8x8->setObjectName(QString::fromUtf8("action8x8"));
        action16x16 = new QAction(MainWindow);
        action16x16->setObjectName(QString::fromUtf8("action16x16"));
        action32x32 = new QAction(MainWindow);
        action32x32->setObjectName(QString::fromUtf8("action32x32"));
        action64x64 = new QAction(MainWindow);
        action64x64->setObjectName(QString::fromUtf8("action64x64"));
        actionAnimated_GIF = new QAction(MainWindow);
        actionAnimated_GIF->setObjectName(QString::fromUtf8("actionAnimated_GIF"));
        actionCurrentFrame = new QAction(MainWindow);
        actionCurrentFrame->setObjectName(QString::fromUtf8("actionCurrentFrame"));
        actionAll_Frames = new QAction(MainWindow);
        actionAll_Frames->setObjectName(QString::fromUtf8("actionAll_Frames"));
        actionSprite_Sheet = new QAction(MainWindow);
        actionSprite_Sheet->setObjectName(QString::fromUtf8("actionSprite_Sheet"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        framePreview = new QFrame(centralwidget);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));
        framePreview->setGeometry(QRect(10, 100, 161, 201));
        framePreview->setFrameShape(QFrame::StyledPanel);
        framePreview->setFrameShadow(QFrame::Raised);
        spinBoxSpeed = new QSpinBox(framePreview);
        spinBoxSpeed->setObjectName(QString::fromUtf8("spinBoxSpeed"));
        spinBoxSpeed->setGeometry(QRect(110, 170, 41, 21));
        spinBoxSpeed->setMinimum(1);
        spinBoxSpeed->setMaximum(24);
        spinBoxSpeed->setValue(12);
        labelSpeed = new QLabel(framePreview);
        labelSpeed->setObjectName(QString::fromUtf8("labelSpeed"));
        labelSpeed->setGeometry(QRect(68, 170, 31, 21));
        labelSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelPreview = new QLabel(framePreview);
        labelPreview->setObjectName(QString::fromUtf8("labelPreview"));
        labelPreview->setGeometry(QRect(0, 0, 161, 161));
        labelPreview->setAutoFillBackground(false);
        labelPreview->setStyleSheet(QString::fromUtf8("background-image: url(:/grayscale/tool_icons/transparency.png);"));
        labelPreview->setFrameShape(QFrame::StyledPanel);
        labelPreview->setScaledContents(false);
        labelPreview->setAlignment(Qt::AlignCenter);
        zoomLevelCheckbox = new QCheckBox(framePreview);
        zoomLevelCheckbox->setObjectName(QString::fromUtf8("zoomLevelCheckbox"));
        zoomLevelCheckbox->setGeometry(QRect(10, 170, 41, 21));
        zoomLevelCheckbox->setLayoutDirection(Qt::RightToLeft);
        zoomLevelCheckbox->setTristate(false);
        frameToolsAndPalette = new QFrame(centralwidget);
        frameToolsAndPalette->setObjectName(QString::fromUtf8("frameToolsAndPalette"));
        frameToolsAndPalette->setGeometry(QRect(10, 330, 161, 271));
        frameToolsAndPalette->setFrameShape(QFrame::StyledPanel);
        frameToolsAndPalette->setFrameShadow(QFrame::Raised);
        eraserToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons = new QButtonGroup(MainWindow);
        toolButtons->setObjectName(QString::fromUtf8("toolButtons"));
        toolButtons->addButton(eraserToolButton);
        eraserToolButton->setObjectName(QString::fromUtf8("eraserToolButton"));
        eraserToolButton->setGeometry(QRect(80, 47, 32, 32));
        eraserToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/grayscale/tool_icons/eraser_tool_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserToolButton->setIcon(icon);
        eraserToolButton->setIconSize(QSize(64, 64));
        eraserToolButton->setCheckable(true);
        eraserToolButton->setChecked(false);
        mirrorPenToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(mirrorPenToolButton);
        mirrorPenToolButton->setObjectName(QString::fromUtf8("mirrorPenToolButton"));
        mirrorPenToolButton->setGeometry(QRect(120, 10, 32, 32));
        mirrorPenToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/grayscale/tool_icons/mirror_pen_tool_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        mirrorPenToolButton->setIcon(icon1);
        mirrorPenToolButton->setIconSize(QSize(64, 64));
        mirrorPenToolButton->setCheckable(true);
        ditheringPenToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(ditheringPenToolButton);
        ditheringPenToolButton->setObjectName(QString::fromUtf8("ditheringPenToolButton"));
        ditheringPenToolButton->setGeometry(QRect(120, 47, 32, 32));
        ditheringPenToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/grayscale/tool_icons/dithering_tool_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ditheringPenToolButton->setIcon(icon2);
        ditheringPenToolButton->setIconSize(QSize(64, 64));
        ditheringPenToolButton->setCheckable(true);
        colorFillToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(colorFillToolButton);
        colorFillToolButton->setObjectName(QString::fromUtf8("colorFillToolButton"));
        colorFillToolButton->setGeometry(QRect(120, 84, 32, 32));
        colorFillToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/colored/images/fill-color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorFillToolButton->setIcon(icon3);
        colorFillToolButton->setIconSize(QSize(24, 24));
        colorFillToolButton->setCheckable(true);
        bucketPenToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(bucketPenToolButton);
        bucketPenToolButton->setObjectName(QString::fromUtf8("bucketPenToolButton"));
        bucketPenToolButton->setGeometry(QRect(80, 84, 32, 32));
        bucketPenToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/colored/images/icons8-color-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        bucketPenToolButton->setIcon(icon4);
        bucketPenToolButton->setIconSize(QSize(24, 24));
        bucketPenToolButton->setCheckable(true);
        ellipseToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(ellipseToolButton);
        ellipseToolButton->setObjectName(QString::fromUtf8("ellipseToolButton"));
        ellipseToolButton->setGeometry(QRect(120, 121, 32, 32));
        ellipseToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/grayscale/tool_icons/ellipse_tool_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ellipseToolButton->setIcon(icon5);
        ellipseToolButton->setIconSize(QSize(32, 32));
        ellipseToolButton->setCheckable(true);
        rectangleToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(rectangleToolButton);
        rectangleToolButton->setObjectName(QString::fromUtf8("rectangleToolButton"));
        rectangleToolButton->setGeometry(QRect(80, 121, 32, 32));
        rectangleToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/grayscale/tool_icons/rectangle_tool_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleToolButton->setIcon(icon6);
        rectangleToolButton->setIconSize(QSize(32, 32));
        rectangleToolButton->setCheckable(true);
        color1Box = new QToolButton(frameToolsAndPalette);
        color1Box->setObjectName(QString::fromUtf8("color1Box"));
        color1Box->setGeometry(QRect(84, 200, 42, 42));
        color1Box->setStyleSheet(QString::fromUtf8("background-color: rgb(12, 12, 12);\n"
""));
        color1Box->setAutoRaise(true);
        penToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(penToolButton);
        penToolButton->setObjectName(QString::fromUtf8("penToolButton"));
        penToolButton->setGeometry(QRect(80, 10, 32, 32));
        penToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/colored/images/icons8-pencil-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        penToolButton->setIcon(icon7);
        penToolButton->setIconSize(QSize(24, 24));
        penToolButton->setCheckable(true);
        penToolButton->setChecked(true);
        color2Box = new QToolButton(frameToolsAndPalette);
        color2Box->setObjectName(QString::fromUtf8("color2Box"));
        color2Box->setGeometry(QRect(104, 221, 42, 42));
        color2Box->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(61, 171, 255);"));
        color2Box->setAutoExclusive(false);
        color2Box->setAutoRaise(true);
        rectangularSelectionToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(rectangularSelectionToolButton);
        rectangularSelectionToolButton->setObjectName(QString::fromUtf8("rectangularSelectionToolButton"));
        rectangularSelectionToolButton->setGeometry(QRect(80, 158, 32, 32));
        rectangularSelectionToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/colored/images/icons8-select-none-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangularSelectionToolButton->setIcon(icon8);
        rectangularSelectionToolButton->setIconSize(QSize(32, 32));
        rectangularSelectionToolButton->setCheckable(true);
        lineToolButton = new QToolButton(frameToolsAndPalette);
        toolButtons->addButton(lineToolButton);
        lineToolButton->setObjectName(QString::fromUtf8("lineToolButton"));
        lineToolButton->setGeometry(QRect(120, 158, 32, 32));
        lineToolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/colored/images/icons8-line-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineToolButton->setIcon(icon9);
        lineToolButton->setIconSize(QSize(32, 32));
        lineToolButton->setCheckable(true);
        palette1 = new QToolButton(frameToolsAndPalette);
        paletteButtons = new QButtonGroup(MainWindow);
        paletteButtons->setObjectName(QString::fromUtf8("paletteButtons"));
        paletteButtons->addButton(palette1);
        palette1->setObjectName(QString::fromUtf8("palette1"));
        palette1->setGeometry(QRect(10, 20, 21, 21));
        palette1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette1->setAutoRaise(true);
        palette2 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette2);
        palette2->setObjectName(QString::fromUtf8("palette2"));
        palette2->setGeometry(QRect(40, 20, 21, 21));
        palette2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette2->setAutoRaise(true);
        palette3 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette3);
        palette3->setObjectName(QString::fromUtf8("palette3"));
        palette3->setGeometry(QRect(10, 50, 21, 21));
        palette3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette3->setAutoRaise(true);
        palette4 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette4);
        palette4->setObjectName(QString::fromUtf8("palette4"));
        palette4->setGeometry(QRect(40, 50, 21, 21));
        palette4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette4->setAutoRaise(true);
        palette7 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette7);
        palette7->setObjectName(QString::fromUtf8("palette7"));
        palette7->setGeometry(QRect(10, 110, 21, 21));
        palette7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette7->setAutoRaise(true);
        palette5 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette5);
        palette5->setObjectName(QString::fromUtf8("palette5"));
        palette5->setGeometry(QRect(10, 80, 21, 21));
        palette5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette5->setAutoRaise(true);
        palette6 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette6);
        palette6->setObjectName(QString::fromUtf8("palette6"));
        palette6->setGeometry(QRect(40, 80, 21, 21));
        palette6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette6->setAutoRaise(true);
        palette8 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette8);
        palette8->setObjectName(QString::fromUtf8("palette8"));
        palette8->setGeometry(QRect(40, 110, 21, 21));
        palette8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette8->setAutoRaise(true);
        palette11 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette11);
        palette11->setObjectName(QString::fromUtf8("palette11"));
        palette11->setGeometry(QRect(10, 170, 21, 21));
        palette11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette11->setAutoRaise(true);
        palette9 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette9);
        palette9->setObjectName(QString::fromUtf8("palette9"));
        palette9->setGeometry(QRect(10, 140, 21, 21));
        palette9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette9->setAutoRaise(true);
        palette10 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette10);
        palette10->setObjectName(QString::fromUtf8("palette10"));
        palette10->setGeometry(QRect(40, 140, 21, 21));
        palette10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette10->setAutoRaise(true);
        palette12 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette12);
        palette12->setObjectName(QString::fromUtf8("palette12"));
        palette12->setGeometry(QRect(40, 170, 21, 21));
        palette12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette12->setAutoRaise(true);
        palette15 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette15);
        palette15->setObjectName(QString::fromUtf8("palette15"));
        palette15->setGeometry(QRect(10, 230, 21, 21));
        palette15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette15->setAutoRaise(true);
        palette16 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette16);
        palette16->setObjectName(QString::fromUtf8("palette16"));
        palette16->setGeometry(QRect(40, 230, 21, 21));
        palette16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette16->setAutoRaise(true);
        palette13 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette13);
        palette13->setObjectName(QString::fromUtf8("palette13"));
        palette13->setGeometry(QRect(10, 200, 21, 21));
        palette13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette13->setAutoRaise(true);
        palette14 = new QToolButton(frameToolsAndPalette);
        paletteButtons->addButton(palette14);
        palette14->setObjectName(QString::fromUtf8("palette14"));
        palette14->setGeometry(QRect(40, 200, 21, 21));
        palette14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        palette14->setAutoRaise(true);
        swapColors = new QToolButton(frameToolsAndPalette);
        swapColors->setObjectName(QString::fromUtf8("swapColors"));
        swapColors->setGeometry(QRect(83, 242, 21, 21));
        swapColors->setAutoFillBackground(true);
        swapColors->setAutoRaise(true);
        swapColors->raise();
        eraserToolButton->raise();
        mirrorPenToolButton->raise();
        ditheringPenToolButton->raise();
        colorFillToolButton->raise();
        bucketPenToolButton->raise();
        ellipseToolButton->raise();
        rectangleToolButton->raise();
        penToolButton->raise();
        color2Box->raise();
        rectangularSelectionToolButton->raise();
        color1Box->raise();
        lineToolButton->raise();
        palette1->raise();
        palette2->raise();
        palette3->raise();
        palette4->raise();
        palette7->raise();
        palette5->raise();
        palette6->raise();
        palette8->raise();
        palette11->raise();
        palette9->raise();
        palette10->raise();
        palette12->raise();
        palette15->raise();
        palette16->raise();
        palette13->raise();
        palette14->raise();
        graphicsViewCanvas = new QGraphicsView(centralwidget);
        graphicsViewCanvas->setObjectName(QString::fromUtf8("graphicsViewCanvas"));
        graphicsViewCanvas->setEnabled(false);
        graphicsViewCanvas->setGeometry(QRect(180, 100, 501, 501));
        graphicsViewCanvas->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        graphicsViewCanvas->setMouseTracking(true);
        graphicsViewCanvas->setStyleSheet(QString::fromUtf8("background-image: url(:/grayscale/tool_icons/transparency.png);"));
        graphicsViewCanvas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewCanvas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewCanvas->setDragMode(QGraphicsView::NoDrag);
        scrollAreaFrameContainer = new QScrollArea(centralwidget);
        scrollAreaFrameContainer->setObjectName(QString::fromUtf8("scrollAreaFrameContainer"));
        scrollAreaFrameContainer->setGeometry(QRect(10, 10, 671, 81));
        scrollAreaFrameContainer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaFrameContainer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaFrameContainer->setWidgetResizable(true);
        frameContainer = new QWidget();
        frameContainer->setObjectName(QString::fromUtf8("frameContainer"));
        frameContainer->setGeometry(QRect(0, 0, 669, 79));
        horizontalLayout = new QHBoxLayout(frameContainer);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scrollAreaFrameContainer->setWidget(frameContainer);
        pushButtonAddFrame = new QPushButton(centralwidget);
        pushButtonAddFrame->setObjectName(QString::fromUtf8("pushButtonAddFrame"));
        pushButtonAddFrame->setGeometry(QRect(649, 10, 31, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 690, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuEDit = new QMenu(menubar);
        menuEDit->setObjectName(QString::fromUtf8("menuEDit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEDit->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(menuExport->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuNew->addAction(action8x8);
        menuNew->addAction(action16x16);
        menuNew->addAction(action32x32);
        menuNew->addAction(action64x64);
        menuExport->addAction(actionAnimated_GIF);
        menuExport->addAction(actionCurrentFrame);
        menuExport->addAction(actionAll_Frames);
        menuExport->addAction(actionSprite_Sheet);
        menuEDit->addAction(actionUndo);
        menuEDit->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        action8x8->setText(QCoreApplication::translate("MainWindow", "8x8", nullptr));
        action16x16->setText(QCoreApplication::translate("MainWindow", "16x16", nullptr));
        action32x32->setText(QCoreApplication::translate("MainWindow", "32x32", nullptr));
        action64x64->setText(QCoreApplication::translate("MainWindow", "64x64", nullptr));
        actionAnimated_GIF->setText(QCoreApplication::translate("MainWindow", "Animated GIF", nullptr));
        actionCurrentFrame->setText(QCoreApplication::translate("MainWindow", "Current Frame", nullptr));
        actionAll_Frames->setText(QCoreApplication::translate("MainWindow", "All Frames", nullptr));
        actionSprite_Sheet->setText(QCoreApplication::translate("MainWindow", "Sprite Sheet", nullptr));
        labelSpeed->setText(QCoreApplication::translate("MainWindow", "FPS:", nullptr));
        labelPreview->setText(QString());
        zoomLevelCheckbox->setText(QCoreApplication::translate("MainWindow", "1:1", nullptr));
        eraserToolButton->setText(QString());
        mirrorPenToolButton->setText(QString());
        ditheringPenToolButton->setText(QString());
        colorFillToolButton->setText(QString());
        bucketPenToolButton->setText(QString());
        ellipseToolButton->setText(QString());
        rectangleToolButton->setText(QString());
        color1Box->setText(QString());
        penToolButton->setText(QString());
        color2Box->setText(QString());
        rectangularSelectionToolButton->setText(QString());
        lineToolButton->setText(QString());
        palette1->setText(QString());
        palette2->setText(QString());
        palette3->setText(QString());
        palette4->setText(QString());
        palette7->setText(QString());
        palette5->setText(QString());
        palette6->setText(QString());
        palette8->setText(QString());
        palette11->setText(QString());
        palette9->setText(QString());
        palette10->setText(QString());
        palette12->setText(QString());
        palette15->setText(QString());
        palette16->setText(QString());
        palette13->setText(QString());
        palette14->setText(QString());
        swapColors->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        pushButtonAddFrame->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuNew->setTitle(QCoreApplication::translate("MainWindow", "New", nullptr));
        menuExport->setTitle(QCoreApplication::translate("MainWindow", "Export", nullptr));
        menuEDit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
