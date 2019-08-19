//
//  convertutils.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/19.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "convertutils.hpp"

#include <sstream>

using namespace std;


namespace foundation
{
    string intVec2Str(const vector<int> &intVec)
    {
        stringbuf buf;
        ostream out(&buf);
        
        out << "[";
        for (size_t idx = 0; idx < intVec.size(); idx++) {
            if (0 != idx) {
                out << ", " << intVec[idx];
            } else {
                out << intVec[idx];
            }
        }
        out << "]";
        return buf.str();
    }
    
    string dataList2Str(const vector<HFDataItem<HFNumberItem>> &dataList)
    {
        stringbuf buf;
        ostream out(&buf);
        
        out << "[";
        for (size_t idx = 0; idx < dataList.size(); idx++) {
            if (0 != idx) {
                out << ", " << dataList[idx].stringVal();
            } else {
                out << dataList[idx].stringVal();
            }
        }
        out << "]";
        return buf.str();
    }
    
    vector<HFDataItem<HFNumberItem>> intVec2DataList(const vector<int> &intVec)
    {
        vector<HFDataItem<HFNumberItem>> dataList;
        for (size_t idx = 0; idx < intVec.size(); idx++) {
            dataList.push_back(HFNumberItem(intVec[idx]));
        }
        return dataList;
    }
}
