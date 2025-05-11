/****************************************************************************
** Meta object code from reading C++ file 'RoiManager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/RoiManager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RoiManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10RoiManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto RoiManager::qt_create_metaobjectdata<qt_meta_tag_ZN10RoiManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RoiManager",
        "selectedROIDimensionChanged",
        "",
        "deleteAll",
        "deleteSelected",
        "selectROI",
        "idx",
        "clearSelection",
        "selectAll",
        "setROIBorderWidth",
        "s",
        "updateBoundaries",
        "w",
        "h",
        "loadAnnotation",
        "std::vector<QGraphicsRectItem*>",
        "filepath",
        "saveAnnotation",
        "setMessageHandler",
        "QtMessageHandler",
        "logger"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'selectedROIDimensionChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'deleteAll'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'deleteSelected'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectROI'
        QtMocHelpers::SlotData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'clearSelection'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearSelection'
        QtMocHelpers::SlotData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setROIBorderWidth'
        QtMocHelpers::SlotData<void(double)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 10 },
        }}),
        // Slot 'updateBoundaries'
        QtMocHelpers::SlotData<void(qreal, qreal)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 12 }, { QMetaType::QReal, 13 },
        }}),
        // Slot 'loadAnnotation'
        QtMocHelpers::SlotData<std::vector<QGraphicsRectItem*>(QString)>(14, 2, QMC::AccessPublic, 0x80000000 | 15, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'saveAnnotation'
        QtMocHelpers::SlotData<void(QString)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'setMessageHandler'
        QtMocHelpers::SlotData<void(QtMessageHandler)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 20 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<RoiManager, qt_meta_tag_ZN10RoiManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject RoiManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10RoiManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10RoiManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10RoiManagerE_t>.metaTypes,
    nullptr
} };

void RoiManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RoiManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->selectedROIDimensionChanged(); break;
        case 1: _t->deleteAll(); break;
        case 2: _t->deleteSelected(); break;
        case 3: _t->selectROI((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->clearSelection(); break;
        case 5: _t->clearSelection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->selectAll(); break;
        case 7: _t->setROIBorderWidth((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->updateBoundaries((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 9: { std::vector<QGraphicsRectItem*> _r = _t->loadAnnotation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<QGraphicsRectItem*>*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->saveAnnotation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->setMessageHandler((*reinterpret_cast< std::add_pointer_t<QtMessageHandler>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (RoiManager::*)()>(_a, &RoiManager::selectedROIDimensionChanged, 0))
            return;
    }
}

const QMetaObject *RoiManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoiManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10RoiManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RoiManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void RoiManager::selectedROIDimensionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
