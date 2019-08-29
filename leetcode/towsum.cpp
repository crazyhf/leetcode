//
//  towsum.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "towsum.hpp"
#include <map>

using namespace std;
using namespace leetcode;


vector<HFTwoSumSolution::TestParam> HFTwoSumSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .nums={2, 7, 11, 15}, .target=9, .expect={0, 1} });
    
    return paramVec;
}

void HFTwoSumSolution::testTwoSum()
{
    cout << "===============================================" << endl
         << "HFTwoSumSolution (1. 两数之和) :" << endl
         << "给定一个整数数组nums和一个目标值target," << endl
         << "请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        vector<int> result = twoSum2(param.nums, param.target);
        cout << endl << "Input : " << intVec2Str(param.nums) << endl
             << "        " << param.target << endl
             << "Output: " << intVec2Str(result) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

vector<int> HFTwoSumSolution::twoSum(vector<int> &nums, int target)
{
    vector<int> diffVals;
    for (int idx = 0; idx < nums.size(); idx++) {
        int diffVal = target - nums[idx];
        for (int jdx = 0; jdx < diffVals.size(); jdx++) {
            if (nums[idx] == diffVals[jdx]) {
                return vector<int>({ jdx, idx });
            }
        }
        diffVals.push_back(diffVal);
    }
    return vector<int>();
}

vector<int> HFTwoSumSolution::twoSum2(vector<int> &nums, int target)
{
    map<int, int> diffMap;
    for (int idx = 0; idx < nums.size(); idx++) {
        map<int, int>::const_iterator ite = diffMap.find(nums[idx]);
        if (diffMap.end() != ite) {
            return vector<int>({ ite->second, idx });
        } else {
            int diffVal = target - nums[idx];
            if (diffMap.end() == diffMap.find(diffVal)) {
                diffMap[diffVal] = idx;
            }
        }
    }
    return vector<int>();
}
