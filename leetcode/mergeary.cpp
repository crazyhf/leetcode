//
//  mergeary.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "mergeary.hpp"

using namespace std;
using namespace leetcode;


vector<HFMergeArySolution::TestParam> HFMergeArySolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .nums1={1, 2, 3, 0, 0, 0}, .m=3, .nums2={2, 5, 6}, .n=3,
                         .expect={1, 2, 2, 3, 5, 6}
    });
    paramVec.push_back({ .nums1={0}, .m=0, .nums2={1}, .n=1,
                         .expect={1}
    });
    return paramVec;
}

void HFMergeArySolution::testMerge()
{
    cout << "===============================================" << endl
         << "HFMergeArySolution :" << endl
         << "给定两个有序整数数组nums1和nums2，将nums2合并到nums1中，使得num1成为一个有序数组。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        
        cout << endl << "Input : " << intVec2Str(param.nums1) << " , " << param.m << endl
             << "        " << intVec2Str(param.nums2) << " , " << param.n << endl;
        merge(param.nums1, param.m, param.nums2, param.n);
        cout << "Output: " << intVec2Str(param.nums1) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

void HFMergeArySolution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int idx = m - 1, jdx = n - 1, kdx = m + n - 1;
    while (kdx >= 0) {
        if (idx >= 0 && jdx >= 0) {
            if (nums1[idx] > nums2[jdx]) {
                nums1[kdx--] = nums1[idx--];
            } else if (nums1[idx] < nums2[jdx]) {
                nums1[kdx--] = nums2[jdx--];
            } else {
                nums1[kdx--] = nums1[idx--];
                nums1[kdx--] = nums2[jdx--];
            }
        } else if (idx >= 0) {
            nums1[kdx--] = nums1[idx--];
        } else {
            nums1[kdx--] = nums2[jdx--];
        }
    }
}
