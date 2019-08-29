//
//  midoftwosortedary.cpp
//  leetcode
//
//  Created by HavenLin on 2019/8/29.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "midoftwosortedary.hpp"

using namespace std;
using namespace leetcode;


vector<HFMidOfTwoSortedArySolution::TestParam> HFMidOfTwoSortedArySolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .nums1={1, 3}, .nums2={2}, .expect=2.0 });
    paramVec.push_back({ .nums1={1, 2}, .nums2={3, 4}, .expect=2.5 });
    return paramVec;
}

void HFMidOfTwoSortedArySolution::testFindMidSortedArys()
{
    cout << "===============================================" << endl
         << "HFMidOfTwoSortedArySolution (4. 寻找两个有序数组的中位数) :" << endl
         << "给定两个大小为m和n的有序数组nums1和nums2。" << endl
         << "请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为O(log(m + n))。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        double result = findMidSortedArys(param.nums1, param.nums2);
        cout << endl << "Input : " << intVec2Str(param.nums1) << endl
             << "        " << intVec2Str(param.nums2) << endl
             << "Output: " << result << endl
             << "Expect: " << param.expect << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

double HFMidOfTwoSortedArySolution::findMidSortedArys(vector<int> &nums1, vector<int> &nums2)
{
    size_t length = nums1.size() + nums2.size();
    size_t result = (length - 1) / 2;
    
    size_t idx = 0, jdx = 0, kdx = 0;
    double midNum1 = 0, midNum2 = 0;
    for (;idx < length && idx <= result + 1; idx++) {
        double num = 0;
        if (jdx < nums1.size() && kdx < nums2.size()) {
            if (nums1[jdx] < nums2[kdx]) {
                num = nums1[jdx++];
            } else {
                num = nums2[kdx++];
            }
        } else if (jdx < nums1.size()) {
            num = nums1[jdx++];
        } else {
            num = nums2[kdx++];
        }
        if (idx <= result) { midNum1 = num; } else { midNum2 = num; }
    }
    return (0 == length % 2 ? (midNum1 + midNum2) / 2 : midNum1);
}
