//
//  spiralmatrix.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/12.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#include "spiralmatrix.hpp"

using namespace std;
using namespace leetcode;


vector<HFSpiralMatrixSolution::TestParam> HFSpiralMatrixSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .matrix={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                         .expect={1,2,3,6,9,8,7,4,5} });
    paramVec.push_back({ .matrix={{1, 2, 3, 4}, {5, 6, 7, 8}, {9,10,11,12}},
                         .expect={1,2,3,4,8,12,11,10,9,5,6,7} });
    return paramVec;
}

void HFSpiralMatrixSolution::testSpiralOrder()
{
    cout << "===============================================" << endl
         << "HFSpiralMatrixSolution (54. 螺旋矩阵) :" << endl
         << "给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        vector<int> result = spiralOrder(param.matrix);
        cout << endl << "Input : " << intVec2Str(param.matrix) << endl
             << "Output: " << intVec2Str(result) << endl
             << "Expect: " << intVec2Str(param.expect) << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

vector<int> HFSpiralMatrixSolution::spiralOrder(vector<vector<int>> &matrix)
{
    int top = 0, left = 0, bottom = (int)matrix.size() - 1, right = -1;
    if (bottom >= 0) {
        right = (int)matrix[0].size() - 1;
    }
    
    vector<int> result;
    while (right >= left && bottom >= top) {
        for (int idx = left; idx <= right; idx++) {
            result.push_back(matrix[top][idx]);
        }
        top++;
        for (int idx = top; idx <= bottom; idx++) {
            result.push_back(matrix[idx][right]);
        }
        right--;
        
        if (bottom >= top) {
            for (int idx = right; idx >= left; idx--) {
                result.push_back(matrix[bottom][idx]);
            }
            bottom--;
        }
        if (right >= left) {
            for (int idx = bottom; idx >= top; idx--) {
                result.push_back(matrix[idx][left]);
            }
            left++;
        }
    }
    return result;
}
