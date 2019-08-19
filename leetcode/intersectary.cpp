//
//  intersectary.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "intersectary.hpp"

#include "quicksort.hpp"

#include "convertutils.hpp"

using namespace std;
using namespace leetcode;


vector<HFIntersectArySolution::TestParam> HFIntersectArySolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .nums1={1, 2, 3}, .nums2={2, 5, 6},
                         .expect={2}
    });
    paramVec.push_back({ .nums1={}, .nums2={1},
                         .expect={}
    });
    paramVec.push_back({ .nums1={1, 2, 2, 1}, .nums2={2, 2},
                         .expect={2}
    });
    paramVec.push_back({ .nums1={4, 9, 5}, .nums2={9, 4, 9, 8, 4},
                         .expect={9, 4}
    });
    return paramVec;
}

void HFIntersectArySolution::testIntersection()
{
    cout << "===============================================" << endl
         << "HFIntersectArySolution :" << endl
         << "给定两个数组，编写一个函数来计算它们的交集。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        vector<int> result = intersection(param.nums1, param.nums2);
        cout << endl << "Input : " << intVec2Str(param.nums1) << endl
             << "        " << intVec2Str(param.nums2) << endl
             << "Output: " << intVec2Str(result) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

vector<int> HFIntersectArySolution::intersection(vector<int>& nums1, vector<int>& nums2)
{
    return vector<int>();
}
