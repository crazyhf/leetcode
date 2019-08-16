//
//  numtrees.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef numtrees_hpp
#define numtrees_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/unique-binary-search-trees
     *
     *  96. 不同的二叉搜索树
     *
     *  给定一个整数n，求以1 ... n为节点组成的二叉搜索树有多少种？
     *
     *  示例:
     *      输入: 3
     *      输出: 5
     *      解释:
     *          给定n = 3,一共有5种不同结构的二叉搜索树:
     *
     *          1         3     3      2      1
     *           \       /     /      / \      \
     *            3     2     1      1   3      2
     *           /     /       \                 \
     *          2     1         2                 3
     */
    class HFNumTreesSolution : HFSolution
    {
    private:
        struct TestParam {
            int nodeNum;
            int expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testNumTrees();
        
        int numTrees(int n);
        
        int numTrees2(int n);
    };
}

#endif /* numtrees_hpp */
