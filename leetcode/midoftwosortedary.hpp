//
//  midoftwosortedary.hpp
//  leetcode
//
//  Created by HavenLin on 2019/8/29.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef midoftwosortedary_hpp
#define midoftwosortedary_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/median-of-two-sorted-arrays
     *
     *  4. 寻找两个有序数组的中位数
     *
     *  给定两个大小为m和n的有序数组nums1和nums2。
     *  请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为O(log(m + n))。
     *  你可以假设nums1和nums2不会同时为空。
     *
     *  示例 1:
     *      nums1 = [1, 3]
     *      nums2 = [2]
     *      则中位数是 2.0
     *
     *  示例 2:
     *      nums1 = [1, 2]
     *      nums2 = [3, 4]
     *      则中位数是 (2 + 3)/2 = 2.5
     */
    class HFMidOfTwoSortedArySolution : HFSolution
    {
    private:
        struct TestParam {
            std::vector<int> nums1;
            std::vector<int> nums2;
            double expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testFindMidSortedArys();
        
        double findMidSortedArys(std::vector<int> &nums1, std::vector<int> &nums2);
    };
}

#endif /* midoftwosortedary_hpp */
