//
//  towsum.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef towsum_hpp
#define towsum_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/two-sum
     *
     *  1. 两数之和
     *
     *  给定一个整数数组nums和一个目标值target，
     *  请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
     *  你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
     *
     *  示例:
     *      给定 nums = [2, 7, 11, 15], target = 9
     *      因为 nums[0] + nums[1] = 2 + 7 = 9
     *      所以返回 [0, 1]
     */
    class HFTwoSumSolution : HFSolution
    {
    private:
        struct TestParam {
            std::vector<int> nums;
            int target;
            std::vector<int> expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testTwoSum();
        
        std::vector<int> twoSum(std::vector<int> &nums, int target);
        
        std::vector<int> twoSum2(std::vector<int> &nums, int target);
    };
}

#endif /* towsum_hpp */
