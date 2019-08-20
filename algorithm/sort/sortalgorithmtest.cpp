//
//  sortalgorithmtest.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/19.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "sortalgorithmtest.hpp"

#include "convertutils.hpp"
#include "sortalgorithm.hpp"

using namespace std;
using namespace foundation;
using namespace leetcode::algorithm::sort::test;


vector<HFSortAlgorithmTest::TestParam> HFSortAlgorithmTest::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .nums={2, 7, 11, 15},
                         .expect={2, 7, 11, 15}
    });
    paramVec.push_back({ .nums={1, 2, 2, 1},
                         .expect={1, 1, 2, 2}
    });
    paramVec.push_back({ .nums={9, 4, 9, 8, 4},
                         .expect={4, 4, 8, 9, 9}
    });
    return paramVec;
}

void HFSortAlgorithmTest::testQuickSort1()
{
    cout << "===============================================" << endl
         << "HFSortAlgorithmTest testQuickSort1 快速排序 :" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        vector<HFDataItem<HFNumberItem>> list = intVec2DataList(param.nums);
        HFQuickSort<HFDataItem<HFNumberItem>>::sort(list);
        cout << endl << "Input : " << intVec2Str(param.nums) << endl
             << "Output: " << dataList2Str(list) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}

void HFSortAlgorithmTest::testQuickSort2()
{
    cout << "===============================================" << endl
         << "HFSortAlgorithmTest testQuickSort2 快速排序 :" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        cout << endl << "Input : " << intVec2Str(param.nums) << endl;
        HFQuickSort<int>::sort(param.nums);
        cout << "Output: " << intVec2Str(param.nums) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}

void HFSortAlgorithmTest::testBubbleSort1()
{
    cout << "===============================================" << endl
         << "HFSortAlgorithmTest testBubbleSort1 冒泡排序 :" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        vector<HFDataItem<HFNumberItem>> list = intVec2DataList(param.nums);
        HFBubbleSort<HFDataItem<HFNumberItem>>::sort(list);
        cout << endl << "Input : " << intVec2Str(param.nums) << endl
             << "Output: " << dataList2Str(list) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}

void HFSortAlgorithmTest::testBubbleSort2()
{
    cout << "===============================================" << endl
         << "HFSortAlgorithmTest testBubbleSort2 冒泡排序 :" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        cout << endl << "Input : " << intVec2Str(param.nums) << endl;
        HFBubbleSort<int>::sort(param.nums);
        cout << "Output: " << intVec2Str(param.nums) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}
