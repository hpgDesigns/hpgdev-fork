/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Model_t {
    QByteArrayData data[28];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Model_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Model"
QT_MOC_LITERAL(1, 6, 12), // "frameCreated"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "frameUpdated"
QT_MOC_LITERAL(4, 33, 6), // "Frame*"
QT_MOC_LITERAL(5, 40, 12), // "previewFrame"
QT_MOC_LITERAL(6, 53, 10), // "savePrompt"
QT_MOC_LITERAL(7, 64, 15), // "newCanvasSignal"
QT_MOC_LITERAL(8, 80, 9), // "dimension"
QT_MOC_LITERAL(9, 90, 14), // "updateUndoRedo"
QT_MOC_LITERAL(10, 105, 15), // "saveAnimatedGIF"
QT_MOC_LITERAL(11, 121, 8), // "filename"
QT_MOC_LITERAL(12, 130, 14), // "saveFrameToPNG"
QT_MOC_LITERAL(13, 145, 17), // "saveFrameSequence"
QT_MOC_LITERAL(14, 163, 3), // "dir"
QT_MOC_LITERAL(15, 167, 15), // "saveSpriteSheet"
QT_MOC_LITERAL(16, 183, 10), // "saveToFile"
QT_MOC_LITERAL(17, 194, 12), // "loadFromFile"
QT_MOC_LITERAL(18, 207, 15), // "checkSaveStatus"
QT_MOC_LITERAL(19, 223, 13), // "setPreviewFPS"
QT_MOC_LITERAL(20, 237, 4), // "secs"
QT_MOC_LITERAL(21, 242, 14), // "previewDisplay"
QT_MOC_LITERAL(22, 257, 14), // "setActiveFrame"
QT_MOC_LITERAL(23, 272, 5), // "index"
QT_MOC_LITERAL(24, 278, 9), // "dupeFrame"
QT_MOC_LITERAL(25, 288, 11), // "deleteFrame"
QT_MOC_LITERAL(26, 300, 11), // "clearFrames"
QT_MOC_LITERAL(27, 312, 4) // "exit"

    },
    "Model\0frameCreated\0\0frameUpdated\0"
    "Frame*\0previewFrame\0savePrompt\0"
    "newCanvasSignal\0dimension\0updateUndoRedo\0"
    "saveAnimatedGIF\0filename\0saveFrameToPNG\0"
    "saveFrameSequence\0dir\0saveSpriteSheet\0"
    "saveToFile\0loadFromFile\0checkSaveStatus\0"
    "setPreviewFPS\0secs\0previewDisplay\0"
    "setActiveFrame\0index\0dupeFrame\0"
    "deleteFrame\0clearFrames\0exit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       3,    1,  117,    2, 0x06 /* Public */,
       5,    1,  120,    2, 0x06 /* Public */,
       6,    0,  123,    2, 0x06 /* Public */,
       7,    1,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  127,    2, 0x0a /* Public */,
      10,    1,  130,    2, 0x0a /* Public */,
      12,    1,  133,    2, 0x0a /* Public */,
      13,    1,  136,    2, 0x0a /* Public */,
      15,    1,  139,    2, 0x0a /* Public */,
      16,    1,  142,    2, 0x0a /* Public */,
      17,    1,  145,    2, 0x0a /* Public */,
      18,    0,  148,    2, 0x0a /* Public */,
      19,    1,  149,    2, 0x0a /* Public */,
      21,    0,  152,    2, 0x0a /* Public */,
      22,    1,  153,    2, 0x0a /* Public */,
      24,    1,  156,    2, 0x0a /* Public */,
      25,    1,  159,    2, 0x0a /* Public */,
      26,    0,  162,    2, 0x0a /* Public */,
      27,    0,  163,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameCreated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->frameUpdated((*reinterpret_cast< Frame*(*)>(_a[1]))); break;
        case 2: _t->previewFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->savePrompt(); break;
        case 4: _t->newCanvasSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateUndoRedo((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 6: _t->saveAnimatedGIF((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->saveFrameToPNG((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->saveFrameSequence((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->saveSpriteSheet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->saveToFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->loadFromFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->checkSaveStatus(); break;
        case 13: _t->setPreviewFPS((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->previewDisplay(); break;
        case 15: _t->setActiveFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->dupeFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->deleteFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->clearFrames(); break;
        case 19: _t->exit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::frameCreated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(Frame * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::frameUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::previewFrame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::savePrompt)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Model::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::newCanvasSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Model.data,
    qt_meta_data_Model,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Model::frameCreated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::frameUpdated(Frame * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::previewFrame(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Model::savePrompt()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Model::newCanvasSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
