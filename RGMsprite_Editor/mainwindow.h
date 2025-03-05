#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include "canvas.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QColorDialog>
#include <QToolButton>
#include <QButtonGroup>
#include <QList>

//class ScribbleArea;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void resetCanvas();
    void checkSave();

public:
    explicit MainWindow(Model& _model, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newCanvasSlot(int dimension);
    void saveDialog();

private:
    Model *_model;
    Canvas *_canvas = new Canvas();
    Ui::MainWindow *_ui;

    int _canvasSize;
    qreal _pixelSize;
    QList<QToolButton*> _paletteButtons;
    QVector<QColor> _paletteHistory;
    int _paletteHistoryIndex = 0;
    QButtonGroup _frameButtons;
    QString colorToString(QColor color);

    void updatePaletteHistory();
    void newFrame(int index);
    void newCanvas(int dimension);

/********************************************************
 *
 *
 *
protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void open();
    void save();
    void penColor();
    void penWidth();
    void about();
*/
};
#endif // MAINWINDOW_H
