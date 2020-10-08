//
//  datastructtest.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/10.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#include "datastructtest.hpp"

#include "datastruct.hpp"
#include "convertutils.hpp"

using namespace std;
using namespace foundation;
using namespace leetcode::datastruct::test;


vector<HFDataStructTest::TestParam> HFDataStructTest::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .nums={5,  18, 72,  2,  7,
                                11, 15,  8, 27, 36,
                                9,  49, 87, 53, 68} });
    
    paramVec.push_back({ .nums={32, 1,   5, 76, 23, 1} });
    
    paramVec.push_back({ .nums={59, 48, 92, 8, 4} });
    
    paramVec.push_back({ .nums={(int)arc4random(), (int)arc4random(),
                                (int)arc4random(), (int)arc4random(),
                                (int)arc4random(), (int)arc4random()} });
    return paramVec;
}

void HFDataStructTest::testLinkList1()
{
    cout << "===============================================" << endl
         << "HFDataStructTest testLinkList1 链表 HFLinkList :" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        HFLinkList<HFDataItem<HFNumberItem>> list = intVec2DataLinkList(param.nums);
        cout << endl << "Input : " << intVec2Str(param.nums) << endl
             << "Output: " << linkList2Str(list) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}

void HFDataStructTest::testLinkList2()
{
    cout << "===============================================" << endl
         << "HFDataStructTest testLinkList2 链表 HFLinkList :" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        HFLinkList<int> list = intVec2LinkList(param.nums);
        cout << endl << "Input : " << intVec2Str(param.nums) << endl
             << "Output: " << linkList2Str(list) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}
