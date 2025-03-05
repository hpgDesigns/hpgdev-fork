#ifndef MODEL_H
#define MODEL_H

#include <math.h>
#include <frame.h>
#include <QObject>
#include <QStack>
#include <QTimer>
#include <QApplication>
#include <QTextStream>
#include <QFile>
#include <QDir>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);
    void newSurface(int dimension);
    void createFrame();
    void undo();
    void redo();

signals:
    void frameCreated(int);
    void frameUpdated(Frame*);
    void previewFrame(QImage);
    void savePrompt();
    void newCanvasSignal(int dimension);

public slots:
    void updateUndoRedo(QImage);
    void saveAnimatedGIF(QString filename);
    void saveFrameToPNG(QString filename);
    void saveFrameSequence(QString dir);
    void saveSpriteSheet(QString filename);
    void saveToFile(QString filename);
    void loadFromFile(QString filename);
    void checkSaveStatus();
    void setPreviewFPS(int secs);
    void previewDisplay();
    void setActiveFrame(int index);
    void dupeFrame(int index);
    void deleteFrame(int index);
    void clearFrames();
    void exit();

private:
    bool _isSaved = false;   // toggle to true when saved, make false after changes are made
    QList<Frame*> _frames = QList<Frame*>();
    Frame *_currentFrame;
    QTimer _previewAnimTimer;
    int _previewAnimIndex = 0;
    QImage _tempImage;
    QStack<QImage> _undoStack;
    QStack<QImage> _redoStack;


};

#endif // MODEL_H
