//
//  addtwonums_ii.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/20.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef addtwonums_ii_hpp
#define addtwonums_ii_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/add-two-numbers-ii
     *
     *  445. 两数相加 II
     *
     *  给定两个非空链表来代表两个非负整数。
     *  数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
     *  你可以假设除了数字0之外，这两个数字都不会以零开头。
     *
     *  进阶:
     *      如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
     *
     *  示例：
     *      输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
     *      输出: 7 -> 8 -> 0 -> 7
     */
    class HFAddTwoNumsSolutionII : HFSolution
    {
    private:
        struct TestParam {
            ListNode *l1;
            ListNode *l2;
            ListNode *expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testAddTwoNumbers();
        
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    };
}

#endif /* addtwonums_ii_hpp */
