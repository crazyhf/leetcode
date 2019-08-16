//
//  numtrees.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "numtrees.hpp"

using namespace std;
using namespace leetcode;


vector<HFNumTreesSolution::TestParam> HFNumTreesSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .nodeNum=2, .expect=2 });
    paramVec.push_back({ .nodeNum=3, .expect=5 });
    paramVec.push_back({ .nodeNum=5, .expect=42 });
    paramVec.push_back({ .nodeNum=10, .expect=16796 });
    
    return paramVec;
}

void HFNumTreesSolution::testNumTrees()
{
    cout << "===============================================" << endl
         << "HFNumTreesSolution :" << endl
         << "给定一个整数n，求以1 ... n为节点组成的二叉搜索树有多少种？" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        int result = numTrees2(param.nodeNum);
        cout << endl << "Input : " << param.nodeNum << endl
             << "Output: " << result << endl
             << "Expect: " << param.expect << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================
/**
 *  S[0] = 1, S[1] = 1
 *  S[2] = S[0]S[1] + S[1]S[0] = 2
 *  S[3] = S[0]S[2] + S[1]S[1] + S[2]S[0] = 5
 */
int HFNumTreesSolution::numTrees(int n)
{
    if (n < 2) {
        return 1;
    }
    
    vector<int> numVec({ 1, 1 });
    for (int idx = 2; idx <= n; idx++) {
        int num = 0;
        for (int jdx = 0; jdx < idx; jdx++) {
            num += numVec[jdx] * numVec[idx - 1 - jdx];
        }
        numVec.push_back(num);
    }
    return numVec[n];
}

int HFNumTreesSolution::numTrees2(int n)
{
    if (n < 2) return 1;
    
    vector<int> numVec({ 1, 1 });
    for (int idx = 2; idx <= n; idx++) {
        int num = 0, halfIdx = idx / 2;
        for (int jdx = 0; jdx < halfIdx; jdx++) {
            num += numVec[jdx] * numVec[idx - 1 - jdx];
        }
        num *= 2;
        if (0 != idx % 2) {
            num += numVec[halfIdx] * numVec[halfIdx];
        }
        numVec.push_back(num);
    }
    return numVec[n];
}
