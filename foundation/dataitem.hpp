//
//  dataitem.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/31.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef dataitem_hpp
#define dataitem_hpp

#include <assert.h>
#include <stdio.h>

#include <string>

namespace foundation
{
    enum HFComparison {
        EQUAL, BIGGER, LESSER
    };
    enum HFNumberType {
        BOOL,
        CHAR, UCHAR,
        SHORT, USHORT, INT, UINT,
        LONG, ULONG, LONGLONG, ULONGLONG,
        FLOAT, DOUBLE, LONGDOUBLE
    };
    
    template <typename T> class HFNumberTypeObj {
    public:
        static HFNumberType type();
        static std::string name();
    };
    
    class HFNumberItem
    {
    private:
        HFNumberType _type;
        
        union {
            bool                boolVal;
            signed char         charVal;
            unsigned char       uCharVal;
            signed short        shortVal;
            unsigned short      uShortVal;
            signed int          intVal;
            unsigned int        uIntVal;
            signed long         longVal;
            unsigned long       uLongVal;
            signed long long    longLongVal;
            unsigned long long  uLongLongVal;
            float               floatVal;
            double              doubleVal;
            long double         longDoubleVal;
        } _number;
        
    public:
        HFNumberType type() { return _type; }
        
#define HFNUMBERITEM_FUNC_DECLARE(_ret_type_, _ret_field_) \
        HFNumberItem(_ret_type_ _ret_field_); \
        _ret_type_ _ret_field_() const; \
        operator _ret_type_() const;

        HFNUMBERITEM_FUNC_DECLARE(bool, boolVal);
        HFNUMBERITEM_FUNC_DECLARE(signed char, charVal);
        HFNUMBERITEM_FUNC_DECLARE(unsigned char ,uCharVal);
        HFNUMBERITEM_FUNC_DECLARE(signed short, shortVal);
        HFNUMBERITEM_FUNC_DECLARE(unsigned short, uShortVal);
        HFNUMBERITEM_FUNC_DECLARE(signed int, intVal);
        HFNUMBERITEM_FUNC_DECLARE(unsigned int, uIntVal);
        HFNUMBERITEM_FUNC_DECLARE(signed long, longVal);
        HFNUMBERITEM_FUNC_DECLARE(unsigned long, uLongVal);
        HFNUMBERITEM_FUNC_DECLARE(signed long long, longLongVal);
        HFNUMBERITEM_FUNC_DECLARE(unsigned long long, uLongLongVal);
        HFNUMBERITEM_FUNC_DECLARE(float, floatVal);
        HFNUMBERITEM_FUNC_DECLARE(double, doubleVal);
        HFNUMBERITEM_FUNC_DECLARE(long double, longDoubleVal);
#undef HFNUMBERITEM_FUNC_DECLARE
        //bool value() { assert(BOOL == _type && ""); return _number.boolVal; }
    };
    
    template <typename T>
    class HFDataItem
    {
    private:
        T _value;
        
    public:
        HFDataItem(T value) : _value(value) {}
        
        T &value() { return _value; }
        
        const T &value() const { return _value; }
        
        bool operator>(const HFDataItem<T> &) const { return true; }
        
        bool operator<(const HFDataItem<T> &) const { return true; }
        
        bool operator==(const HFDataItem<T> &) const { return true; }
    };
    
//    template <typename T>
//    Comparison compare(const HFDataItem<T> &item1, const HFDataItem<T> &item2)
//    {
//        if (item1 == item2) {
//            return Equal;
//        } else if (item1 > item2) {
//            return Bigger;
//        } else {
//            return Lesser;
//        }
//    }
}

#endif /* dataitem_hpp */
