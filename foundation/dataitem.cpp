//
//  dataitem.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/31.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "dataitem.hpp"

#include <sstream>

using namespace std;


namespace foundation
{
    bool HFNumberTypeIsUnSigned(HFNumberType type)
    {
        return (BOOL == type || UCHAR == type || USHORT == type
                || UINT == type || ULONG == type || ULONGLONG == type);
    }
    
    bool HFNumberTypeIsSigned(HFNumberType type)
    {
        return (CHAR == type || SHORT == type
                || INT == type || LONG == type || LONGLONG == type);
    }
    
    bool HFNumberTypeIsFloat(HFNumberType type)
    {
        return (FLOAT == type || DOUBLE == type || LONGDOUBLE == type);
    }
    
#define HFNUMBERTYPEOBJ_SPECIALIZE(_type_, _number_type_) \
        template<> \
        HFNumberType HFNumberTypeObj<_type_>::type() { return _number_type_; } \
        template <> \
        string HFNumberTypeObj<_type_>::name() { return #_number_type_; }
    
    HFNUMBERTYPEOBJ_SPECIALIZE(bool, BOOL);
    HFNUMBERTYPEOBJ_SPECIALIZE(signed char, CHAR);
    HFNUMBERTYPEOBJ_SPECIALIZE(unsigned char, UCHAR);
    HFNUMBERTYPEOBJ_SPECIALIZE(signed short, SHORT);
    HFNUMBERTYPEOBJ_SPECIALIZE(unsigned short, USHORT);
    HFNUMBERTYPEOBJ_SPECIALIZE(signed int, INT);
    HFNUMBERTYPEOBJ_SPECIALIZE(unsigned int, UINT);
    HFNUMBERTYPEOBJ_SPECIALIZE(signed long, LONG);
    HFNUMBERTYPEOBJ_SPECIALIZE(unsigned long, ULONG);
    HFNUMBERTYPEOBJ_SPECIALIZE(signed long long, LONGLONG);
    HFNUMBERTYPEOBJ_SPECIALIZE(unsigned long long, ULONGLONG);
    HFNUMBERTYPEOBJ_SPECIALIZE(float, FLOAT);
    HFNUMBERTYPEOBJ_SPECIALIZE(double, DOUBLE);
    HFNUMBERTYPEOBJ_SPECIALIZE(long double, LONGDOUBLE);
    
#undef HFNUMBERTYPEOBJ_SPECIALIZE
    
    
    template <typename T>
    HFComparison compareWithNumberItem(T value, const HFNumberItem &item)
    {
        if (HFNumberTypeIsSigned(item.type())) {
            long long v = item.longLongVal();
            if (value > v) { return BIGGER; }
            else if (value == v) { return EQUAL; }
            else { return LESSER; }
        } else if (HFNumberTypeIsUnSigned(item.type())) {
            unsigned long long v = item.uLongLongVal();
            if (value > v) { return BIGGER; }
            else if (value == v) { return EQUAL; }
            else { return LESSER; }
        } else {
            long double v = item.longDoubleVal();
            if (value > v) { return BIGGER; }
            else if (value == v) { return EQUAL; }
            else { return LESSER; }
        }
    }
    
    
    bool HFNumberItem::operator>(const HFNumberItem &item) const
    {
        return (BIGGER == compare(item));
    }
    
    bool HFNumberItem::operator>=(const HFNumberItem &item) const
    {
        return (LESSER != compare(item));
    }
    
    bool HFNumberItem::operator<(const HFNumberItem &item) const
    {
        return (LESSER == compare(item));
    }
    
    bool HFNumberItem::operator<=(const HFNumberItem &item) const
    {
        return (BIGGER != compare(item));
    }
    
    bool HFNumberItem::operator==(const HFNumberItem &item) const
    {
        return (EQUAL == compare(item));
    }
    
    HFComparison HFNumberItem::compare(const HFNumberItem &item) const
    {
        if (HFNumberTypeIsSigned(_type)) {
            return compareWithNumberItem(longLongVal(), item);
        } else if (HFNumberTypeIsUnSigned(_type)) {
            return compareWithNumberItem(uLongLongVal(), item);
        } else {
            return compareWithNumberItem(longDoubleVal(), item);
        }
    }
    
    template <typename T>
    T HFNumberItem::value() const
    {
        switch (_type) {
            case BOOL: return (T)_number.boolVal;
            case CHAR: return (T)_number.charVal;
            case UCHAR: return (T)_number.uCharVal;
            case SHORT: return (T)_number.shortVal;
            case USHORT: return (T)_number.uShortVal;
            case INT: return (T)_number.intVal;
            case UINT: return (T)_number.uIntVal;
            case LONG: return (T)_number.longVal;
            case ULONG: return (T)_number.uLongVal;
            case LONGLONG: return (T)_number.longLongVal;
            case ULONGLONG: return (T)_number.uLongLongVal;
            case FLOAT: return (T)_number.floatVal;
            case DOUBLE: return (T)_number.doubleVal;
            case LONGDOUBLE: return (T)_number.longDoubleVal;
            default: return 0;
        }
    }
    
#define HFNUMBERITEM_FUNC_DEFINE(_ret_type_, _ret_field_) \
        HFNumberItem::HFNumberItem(_ret_type_ _ret_field_) \
                     : _type(HFNumberTypeObj<_ret_type_>::type()), \
                       _number({._ret_field_=_ret_field_}) {} \
        _ret_type_ HFNumberItem::_ret_field_() const { return value<_ret_type_>(); } \
        HFNumberItem::operator _ret_type_() const { return _ret_field_(); }
    
    HFNUMBERITEM_FUNC_DEFINE(bool, boolVal);
    HFNUMBERITEM_FUNC_DEFINE(signed char, charVal);
    HFNUMBERITEM_FUNC_DEFINE(unsigned char ,uCharVal);
    HFNUMBERITEM_FUNC_DEFINE(signed short, shortVal);
    HFNUMBERITEM_FUNC_DEFINE(unsigned short, uShortVal);
    HFNUMBERITEM_FUNC_DEFINE(signed int, intVal);
    HFNUMBERITEM_FUNC_DEFINE(unsigned int, uIntVal);
    HFNUMBERITEM_FUNC_DEFINE(signed long, longVal);
    HFNUMBERITEM_FUNC_DEFINE(unsigned long, uLongVal);
    HFNUMBERITEM_FUNC_DEFINE(signed long long, longLongVal);
    HFNUMBERITEM_FUNC_DEFINE(unsigned long long, uLongLongVal);
    HFNUMBERITEM_FUNC_DEFINE(float, floatVal);
    HFNUMBERITEM_FUNC_DEFINE(double, doubleVal);
    HFNUMBERITEM_FUNC_DEFINE(long double, longDoubleVal);
    
    HFNumberItem::HFNumberItem()
                 : _type(HFNumberTypeObj<signed long long>::type()),
                   _number({.longLongVal = 0}) {}
    
#undef HFNUMBERITEM_FUNC_DEFINE
    
    string HFNumberItem::stringVal() const
    {
        stringbuf buf;
        ostream out(&buf);
        if (HFNumberTypeIsSigned(_type)) {
            out << longLongVal();
        } else if (HFNumberTypeIsUnSigned(_type)) {
            out << uLongLongVal();
        } else {
            out << longDoubleVal();
        }
        return buf.str();
    }
    
    HFNumberItem::operator std::string() const { return stringVal(); }
    
    template<>
    std::string HFDataItem<HFNumberItem>::stringVal() const
    { return _value.stringVal(); }
    
    template<>
    bool HFDataItem<HFNumberItem>::operator>(const HFDataItem &item) const
    { return _value > item.value(); }
    
    template<>
    bool HFDataItem<HFNumberItem>::operator>=(const HFDataItem &item) const
    { return _value >= item.value(); }
    
    template<>
    bool HFDataItem<HFNumberItem>::operator<(const HFDataItem &item) const
    { return _value < item.value(); }
    
    template<>
    bool HFDataItem<HFNumberItem>::operator<=(const HFDataItem &item) const
    { return _value <= item.value(); }
    
    template<>
    bool HFDataItem<HFNumberItem>::operator==(const HFDataItem &item) const
    { return _value == item.value(); }
}
