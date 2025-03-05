#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVector>
#include <QStack>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QPen>
#include <QLabel>
#include <tool.h>
#include <frame.h>


class Canvas : public QGraphicsScene
{
    Q_OBJECT

signals:
    void updateUndo(QImage);
    void frameUpdated(Frame *_frame);
    void pixelsModified(QImage);

public slots:
    void setPrimaryColor(QColor color);
    void setSecondaryColor(QColor color);
    void swapColors();
    void setTool(Tool tool);
    void setFrame(Frame *frame);

private:
    QPoint _rectStartPos;
    int _lastX, _lastY, _startX, _startY;
    int _lastButton;
    std::vector<std::tuple<QPoint, QColor>> _temp;
    int _lastLeft,_lastRight,_lastTop, _lastBottom;
    QColor _primaryColor = QColor(0, 0, 0, 255);
    QColor _secondaryColor = QColor(255, 255, 255, 255);
    QVector<QPoint> _points = QVector<QPoint>();
    Qt::MouseButton _buttonHeld = Qt::NoButton;
    QSizeF _pixSize = QSizeF(32, 32);
    Frame *_frame;
    Tool _tool;
    QRectF _rect;
    QRect _prevRect;
    QPoint _convertedPoint;
    QRect _convertedRect;
    bool _isPaste;
    bool _isCut;
    bool _isRectSelected;
    bool _mouseEnabled = true;
    Tool _lastTool;
    void draw(QPointF point);
    void refresh();
    void normalizeRectSides(QRect r);


public:
    explicit Canvas(QObject *parent = nullptr);
    void setDisableMouse(bool val) { _mouseEnabled = !val; }
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void keyPressEvent(QKeyEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
};

#endif // CANVAS_H
