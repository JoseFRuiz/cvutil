/****************************************************************************
** Meta object code from reading C++ file 'PluginManager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/PluginManager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PluginManager.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13PluginManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto PluginManager::qt_create_metaobjectdata<qt_meta_tag_ZN13PluginManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PluginManager",
        "pluginLoaded",
        "",
        "name",
        "pluginUnloaded",
        "pluginEnabled",
        "enabled",
        "pluginVisible",
        "visible",
        "pluginSelected",
        "selected",
        "pluginColorChanged",
        "color",
        "pluginPenChanged",
        "pen",
        "pluginBrushChanged",
        "brush",
        "pluginZValueChanged",
        "z",
        "pluginTransformChanged",
        "transform",
        "pluginPosChanged",
        "pos",
        "pluginRotationChanged",
        "angle",
        "pluginScaleChanged",
        "scale",
        "pluginShearChanged",
        "shear",
        "pluginTranslationChanged",
        "translation",
        "pluginMatrixChanged",
        "QMatrix",
        "matrix",
        "pluginItemTransformChanged",
        "QGraphicsTransform*",
        "pluginItemFlagsChanged",
        "QGraphicsItem::GraphicsItemFlags",
        "flags",
        "pluginItemCacheModeChanged",
        "QGraphicsItem::CacheMode",
        "mode",
        "pluginItemBoundingRegionGranularityChanged",
        "granularity",
        "pluginItemAcceptDropsChanged",
        "on",
        "pluginItemAcceptHoverEventsChanged",
        "pluginItemAcceptTouchEventsChanged",
        "pluginItemAcceptsHoverEventsChanged",
        "pluginItemAcceptsTouchEventsChanged",
        "pluginItemAcceptsDropsChanged",
        "pluginItemAcceptsHoverChanged",
        "pluginItemAcceptsTouchChanged",
        "pluginItemAcceptsDropChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'pluginLoaded'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'pluginUnloaded'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'pluginEnabled'
        QtMocHelpers::SignalData<void(QString, bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 6 },
        }}),
        // Signal 'pluginVisible'
        QtMocHelpers::SignalData<void(QString, bool)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 8 },
        }}),
        // Signal 'pluginSelected'
        QtMocHelpers::SignalData<void(QString, bool)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 10 },
        }}),
        // Signal 'pluginColorChanged'
        QtMocHelpers::SignalData<void(QString, QColor)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QColor, 12 },
        }}),
        // Signal 'pluginPenChanged'
        QtMocHelpers::SignalData<void(QString, QPen)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QPen, 14 },
        }}),
        // Signal 'pluginBrushChanged'
        QtMocHelpers::SignalData<void(QString, QBrush)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QBrush, 16 },
        }}),
        // Signal 'pluginZValueChanged'
        QtMocHelpers::SignalData<void(QString, qreal)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QReal, 18 },
        }}),
        // Signal 'pluginTransformChanged'
        QtMocHelpers::SignalData<void(QString, QTransform)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QTransform, 20 },
        }}),
        // Signal 'pluginPosChanged'
        QtMocHelpers::SignalData<void(QString, QPointF)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QPointF, 22 },
        }}),
        // Signal 'pluginRotationChanged'
        QtMocHelpers::SignalData<void(QString, qreal)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QReal, 24 },
        }}),
        // Signal 'pluginScaleChanged'
        QtMocHelpers::SignalData<void(QString, QPointF)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QPointF, 26 },
        }}),
        // Signal 'pluginShearChanged'
        QtMocHelpers::SignalData<void(QString, QPointF)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QPointF, 28 },
        }}),
        // Signal 'pluginTranslationChanged'
        QtMocHelpers::SignalData<void(QString, QPointF)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QPointF, 30 },
        }}),
        // Signal 'pluginMatrixChanged'
        QtMocHelpers::SignalData<void(QString, QMatrix)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 32, 33 },
        }}),
        // Signal 'pluginItemTransformChanged'
        QtMocHelpers::SignalData<void(QString, QGraphicsTransform *)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 35, 20 },
        }}),
        // Signal 'pluginItemFlagsChanged'
        QtMocHelpers::SignalData<void(QString, QGraphicsItem::GraphicsItemFlags)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 37, 38 },
        }}),
        // Signal 'pluginItemCacheModeChanged'
        QtMocHelpers::SignalData<void(QString, QGraphicsItem::CacheMode)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 40, 41 },
        }}),
        // Signal 'pluginItemBoundingRegionGranularityChanged'
        QtMocHelpers::SignalData<void(QString, qreal)>(42, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QReal, 43 },
        }}),
        // Signal 'pluginItemAcceptDropsChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptHoverEventsChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptTouchEventsChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(47, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptsHoverEventsChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(48, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptsTouchEventsChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(49, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptsDropsChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(50, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptsHoverChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptsTouchChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(52, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
        // Signal 'pluginItemAcceptsDropChanged'
        QtMocHelpers::SignalData<void(QString, bool)>(53, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 45 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<PluginManager, qt_meta_tag_ZN13PluginManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PluginManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13PluginManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13PluginManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13PluginManagerE_t>.metaTypes,
    nullptr
} };

void PluginManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PluginManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->pluginLoaded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->pluginUnloaded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->pluginEnabled((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 3: _t->pluginVisible((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->pluginSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 5: _t->pluginColorChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        case 6: _t->pluginPenChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPen>>(_a[2]))); break;
        case 7: _t->pluginBrushChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QBrush>>(_a[2]))); break;
        case 8: _t->pluginZValueChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 9: _t->pluginTransformChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTransform>>(_a[2]))); break;
        case 10: _t->pluginPosChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 11: _t->pluginRotationChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 12: _t->pluginScaleChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 13: _t->pluginShearChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 14: _t->pluginTranslationChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 15: _t->pluginMatrixChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMatrix>>(_a[2]))); break;
        case 16: _t->pluginItemTransformChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsTransform*>>(_a[2]))); break;
        case 17: _t->pluginItemFlagsChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsItem::GraphicsItemFlags>>(_a[2]))); break;
        case 18: _t->pluginItemCacheModeChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsItem::CacheMode>>(_a[2]))); break;
        case 19: _t->pluginItemBoundingRegionGranularityChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 20: _t->pluginItemAcceptDropsChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 21: _t->pluginItemAcceptHoverEventsChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 22: _t->pluginItemAcceptTouchEventsChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 23: _t->pluginItemAcceptsHoverEventsChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 24: _t->pluginItemAcceptsTouchEventsChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 25: _t->pluginItemAcceptsDropsChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 26: _t->pluginItemAcceptsHoverChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 27: _t->pluginItemAcceptsTouchChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 28: _t->pluginItemAcceptsDropChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString )>(_a, &PluginManager::pluginLoaded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString )>(_a, &PluginManager::pluginUnloaded, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginEnabled, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginVisible, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginSelected, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QColor )>(_a, &PluginManager::pluginColorChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QPen )>(_a, &PluginManager::pluginPenChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QBrush )>(_a, &PluginManager::pluginBrushChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , qreal )>(_a, &PluginManager::pluginZValueChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QTransform )>(_a, &PluginManager::pluginTransformChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QPointF )>(_a, &PluginManager::pluginPosChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , qreal )>(_a, &PluginManager::pluginRotationChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QPointF )>(_a, &PluginManager::pluginScaleChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QPointF )>(_a, &PluginManager::pluginShearChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QPointF )>(_a, &PluginManager::pluginTranslationChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QMatrix )>(_a, &PluginManager::pluginMatrixChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QGraphicsTransform * )>(_a, &PluginManager::pluginItemTransformChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QGraphicsItem::GraphicsItemFlags )>(_a, &PluginManager::pluginItemFlagsChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , QGraphicsItem::CacheMode )>(_a, &PluginManager::pluginItemCacheModeChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , qreal )>(_a, &PluginManager::pluginItemBoundingRegionGranularityChanged, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptDropsChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptHoverEventsChanged, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptTouchEventsChanged, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptsHoverEventsChanged, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptsTouchEventsChanged, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptsDropsChanged, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptsHoverChanged, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptsTouchChanged, 27))
            return;
        if (QtMocHelpers::indexOfMethod<void (PluginManager::*)(QString , bool )>(_a, &PluginManager::pluginItemAcceptsDropChanged, 28))
            return;
    }
}

const QMetaObject *PluginManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PluginManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13PluginManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PluginManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void PluginManager::pluginLoaded(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void PluginManager::pluginUnloaded(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void PluginManager::pluginEnabled(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void PluginManager::pluginVisible(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void PluginManager::pluginSelected(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void PluginManager::pluginColorChanged(QString _t1, QColor _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void PluginManager::pluginPenChanged(QString _t1, QPen _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void PluginManager::pluginBrushChanged(QString _t1, QBrush _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}

// SIGNAL 8
void PluginManager::pluginZValueChanged(QString _t1, qreal _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}

// SIGNAL 9
void PluginManager::pluginTransformChanged(QString _t1, QTransform _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2);
}

// SIGNAL 10
void PluginManager::pluginPosChanged(QString _t1, QPointF _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1, _t2);
}

// SIGNAL 11
void PluginManager::pluginRotationChanged(QString _t1, qreal _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1, _t2);
}

// SIGNAL 12
void PluginManager::pluginScaleChanged(QString _t1, QPointF _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1, _t2);
}

// SIGNAL 13
void PluginManager::pluginShearChanged(QString _t1, QPointF _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1, _t2);
}

// SIGNAL 14
void PluginManager::pluginTranslationChanged(QString _t1, QPointF _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1, _t2);
}

// SIGNAL 15
void PluginManager::pluginMatrixChanged(QString _t1, QMatrix _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1, _t2);
}

// SIGNAL 16
void PluginManager::pluginItemTransformChanged(QString _t1, QGraphicsTransform * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1, _t2);
}

// SIGNAL 17
void PluginManager::pluginItemFlagsChanged(QString _t1, QGraphicsItem::GraphicsItemFlags _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1, _t2);
}

// SIGNAL 18
void PluginManager::pluginItemCacheModeChanged(QString _t1, QGraphicsItem::CacheMode _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1, _t2);
}

// SIGNAL 19
void PluginManager::pluginItemBoundingRegionGranularityChanged(QString _t1, qreal _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1, _t2);
}

// SIGNAL 20
void PluginManager::pluginItemAcceptDropsChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1, _t2);
}

// SIGNAL 21
void PluginManager::pluginItemAcceptHoverEventsChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1, _t2);
}

// SIGNAL 22
void PluginManager::pluginItemAcceptTouchEventsChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1, _t2);
}

// SIGNAL 23
void PluginManager::pluginItemAcceptsHoverEventsChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1, _t2);
}

// SIGNAL 24
void PluginManager::pluginItemAcceptsTouchEventsChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 24, nullptr, _t1, _t2);
}

// SIGNAL 25
void PluginManager::pluginItemAcceptsDropsChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 25, nullptr, _t1, _t2);
}

// SIGNAL 26
void PluginManager::pluginItemAcceptsHoverChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 26, nullptr, _t1, _t2);
}

// SIGNAL 27
void PluginManager::pluginItemAcceptsTouchChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 27, nullptr, _t1, _t2);
}

// SIGNAL 28
void PluginManager::pluginItemAcceptsDropChanged(QString _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 28, nullptr, _t1, _t2);
}
QT_WARNING_POP
