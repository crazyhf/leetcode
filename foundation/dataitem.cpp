//
//  dataitem.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/31.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "dataitem.hpp"

using namespace std;


namespace foundation
{
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
    
    
#define HFNUMBERITEM_FUNC_DEFINE(_ret_type_, _ret_field_) \
        HFNumberItem::HFNumberItem(_ret_type_ _ret_field_) \
                     : _type(HFNumberTypeObj<_ret_type_>::type()), \
                       _number({._ret_field_=_ret_field_}) {} \
        _ret_type_ HFNumberItem::_ret_field_() const { return _number._ret_field_; } \
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
#undef HFNUMBERITEM_FUNC_DEFINE
}
