#ifndef FRAME_H
#define FRAME_H

#include <QImage>
#include <QPainter>
#include <QStack>
#include <QMap>
#include <QDebug>
#include <QBitmap>

class Frame
{
private:
    QStack<QPoint> _pixelStack;
    QStack<QImage> _undoStack;
    QStack<QImage> _redoStack;
    bool _blankFrame = true;

public:
    std::vector<std::tuple<QPoint, QColor>> _selectionPoints;
    QPainter *_painter;
    QImage _prevRectImage;
    QImage _prevSelectionToolImage;
    QImage _image;
    QImage _tempImage;
    Frame();
    Frame(Frame& f);
    Frame(int dimension);
    ~Frame();
    void drawEllipse(QRect area, QColor line, QColor fill);
    void drawMirrorPen(QPoint point, QColor color);
    void drawPen(QPoint point, QColor color);
    void drawRectangle(QRect area, QColor line, QColor fill);
    void setupDraw(QColor line, QColor fill, QImage temp, QRect area);
    void drawLine(QPoint start, QPoint end, QColor color);
    void erase(QPoint point);
    void bucketFill(QPoint startPoint, QColor initialColor, QColor replacementColor);
    void colorSwap(QPoint startPoint, QColor color);
    void selectRegion(QRect area, QColor line, QColor fill);
    void undo();
    void redo();
    void updateUndoRedo(QImage newImage);
    QImage pixels();
    QSize size();
    int _dimension;
};

#endif // FRAME_H
