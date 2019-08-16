//
//  mergeary.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef mergeary_hpp
#define mergeary_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/merge-sorted-array
     *
     *  88. 合并两个有序数组
     *
     *  给定两个有序整数数组nums1和nums2，将nums2合并到nums1中，使得num1成为一个有序数组。
     *  说明:
     *      初始化nums1和nums2的元素数量分别为m和n。
     *      你可以假设nums1有足够的空间（空间大小大于或等于m + n）来保存nums2中的元素。
     *
     *  示例:
     *      输入:
     *          nums1 = [1,2,3,0,0,0], m = 3
     *          nums2 = [2,5,6],       n = 3
     *      输出:
     *          [1,2,2,3,5,6]
     */
    class HFMergeArySolution : HFSolution
    {
    private:
        struct TestParam {
            std::vector<int> nums1;
            int m;
            std::vector<int> nums2;
            int n;
            std::vector<int> expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testMerge();
        
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
    };
}

#endif /* mergeary_hpp */
