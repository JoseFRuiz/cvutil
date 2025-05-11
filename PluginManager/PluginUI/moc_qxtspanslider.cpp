/****************************************************************************
** Meta object code from reading C++ file 'qxtspanslider.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qxtspanslider.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtspanslider.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QxtSpanSliderE_t {};
} // unnamed namespace

template <> constexpr inline auto QxtSpanSlider::qt_create_metaobjectdata<qt_meta_tag_ZN13QxtSpanSliderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QxtSpanSlider",
        "spanChanged",
        "",
        "lower",
        "upper",
        "lowerValueChanged",
        "upperValueChanged",
        "lowerPositionChanged",
        "upperPositionChanged",
        "sliderPressed",
        "SpanHandle",
        "handle",
        "setLowerValue",
        "setUpperValue",
        "setSpan",
        "setLowerPosition",
        "setUpperPosition",
        "lowerValue",
        "upperValue",
        "lowerPosition",
        "upperPosition",
        "handleMovementMode",
        "HandleMovementMode",
        "FreeMovement",
        "NoCrossing",
        "NoOverlapping"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'spanChanged'
        QtMocHelpers::SignalData<void(int, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 4 },
        }}),
        // Signal 'lowerValueChanged'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'upperValueChanged'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'lowerPositionChanged'
        QtMocHelpers::SignalData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'upperPositionChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'sliderPressed'
        QtMocHelpers::SignalData<void(SpanHandle)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'setLowerValue'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setUpperValue'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'setSpan'
        QtMocHelpers::SlotData<void(int, int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 4 },
        }}),
        // Slot 'setLowerPosition'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setUpperPosition'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'lowerValue'
        QtMocHelpers::PropertyData<int>(17, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'upperValue'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lowerPosition'
        QtMocHelpers::PropertyData<int>(19, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'upperPosition'
        QtMocHelpers::PropertyData<int>(20, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'handleMovementMode'
        QtMocHelpers::PropertyData<HandleMovementMode>(21, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'HandleMovementMode'
        QtMocHelpers::EnumData<HandleMovementMode>(22, 22, QMC::EnumFlags{}).add({
            {   23, HandleMovementMode::FreeMovement },
            {   24, HandleMovementMode::NoCrossing },
            {   25, HandleMovementMode::NoOverlapping },
        }),
    };
    return QtMocHelpers::metaObjectData<QxtSpanSlider, qt_meta_tag_ZN13QxtSpanSliderE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QxtSpanSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QSlider::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QxtSpanSliderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QxtSpanSliderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QxtSpanSliderE_t>.metaTypes,
    nullptr
} };

void QxtSpanSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QxtSpanSlider *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->spanChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->lowerValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->upperValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->lowerPositionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->upperPositionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->sliderPressed((*reinterpret_cast< std::add_pointer_t<SpanHandle>>(_a[1]))); break;
        case 6: _t->setLowerValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setUpperValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->setSpan((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->setLowerPosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setUpperPosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QxtSpanSlider::*)(int , int )>(_a, &QxtSpanSlider::spanChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QxtSpanSlider::*)(int )>(_a, &QxtSpanSlider::lowerValueChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QxtSpanSlider::*)(int )>(_a, &QxtSpanSlider::upperValueChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QxtSpanSlider::*)(int )>(_a, &QxtSpanSlider::lowerPositionChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QxtSpanSlider::*)(int )>(_a, &QxtSpanSlider::upperPositionChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QxtSpanSlider::*)(SpanHandle )>(_a, &QxtSpanSlider::sliderPressed, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->lowerValue(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->upperValue(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->lowerPosition(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->upperPosition(); break;
        case 4: *reinterpret_cast<HandleMovementMode*>(_v) = _t->handleMovementMode(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLowerValue(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setUpperValue(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setLowerPosition(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setUpperPosition(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setHandleMovementMode(*reinterpret_cast<HandleMovementMode*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QxtSpanSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtSpanSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QxtSpanSliderE_t>.strings))
        return static_cast<void*>(this);
    return QSlider::qt_metacast(_clname);
}

int QxtSpanSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QxtSpanSlider::spanChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QxtSpanSlider::lowerValueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QxtSpanSlider::upperValueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QxtSpanSlider::lowerPositionChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QxtSpanSlider::upperPositionChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QxtSpanSlider::sliderPressed(SpanHandle _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
