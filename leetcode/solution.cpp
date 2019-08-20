//
//  solution.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "solution.hpp"

using namespace std;
using namespace leetcode;


string HFSolution::intVec2Str(const vector<int> &intVec)
{
    return foundation::intVec2Str(intVec);
}

void HFSolution::printIntVec(const vector<int> &intVec)
{
    cout << foundation::intVec2Str(intVec);
}
