//
//  longestconsecutivelist.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/15.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef longestconsecutivelist_hpp
#define longestconsecutivelist_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/longest-consecutive-sequence
     *
     *  128. 最长连续序列
     *
     *  给定一个未排序的整数数组，找出最长连续序列的长度。
     *  要求算法的时间复杂度为O(n)。
     *
     *  示例:
     *      输入: [100, 4, 200, 1, 3, 2]
     *      输出: 4
     *      解释: 最长连续序列是[1, 2, 3, 4]。它的长度为4。
     */
    class HFLongestConsecutiveListSolution : HFSolution
    {
    private:
        struct TestParam {
            std::vector<int> nums;
            int expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testLongestConsecutive();
        
        int longestConsecutive(std::vector<int> &nums);
        
        int longestConsecutive2(std::vector<int> &nums);
        
        int longestConsecutive3(std::vector<int> &nums);
    };
}

#endif /* longestconsecutivelist_hpp */
