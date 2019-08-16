//
//  solution.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "solution.hpp"

#include <sstream>

using namespace std;
using namespace leetcode;


string HFSolution::intVec2Str(const vector<int> &intVec)
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

void HFSolution::printIntVec(const vector<int> &intVec)
{
    cout << intVec2Str(intVec);
}
