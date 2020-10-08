//
//  spiralmatrix.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/12.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#ifndef spiralmatrix_hpp
#define spiralmatrix_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/spiral-matrix
     *
     *  54. 螺旋矩阵
     *
     *  给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
     *
     *  示例 1:
     *      输入: [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ]
     *      输出: [1,2,3,6,9,8,7,4,5]
     *
     *  示例 2:
     *      输入: [ [1, 2, 3, 4], [5, 6, 7, 8], [9,10,11,12] ]
     *      输出: [1,2,3,4,8,12,11,10,9,5,6,7]
     */
    class HFSpiralMatrixSolution : HFSolution
    {
    private:
        struct TestParam {
            std::vector<std::vector<int>> matrix;
            std::vector<int> expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testSpiralOrder();
        
        std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix);
    };
}

#endif /* spiralmatrix_hpp */
