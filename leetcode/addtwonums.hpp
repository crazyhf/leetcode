//
//  addtwonums.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/20.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef addtwonums_hpp
#define addtwonums_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/add-two-numbers
     *
     *  2. 两数相加
     *
     *  给出两个非空的链表用来表示两个非负的整数。
     *  其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
     *  如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
     *  您可以假设除了数字0之外，这两个数都不会以0开头。
     *
     *  示例：
     *      输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
     *      输出：7 -> 0 -> 8
     *      原因：342 + 465 = 807
     */
    class HFAddTwoNumsSolution : HFSolution
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

#endif /* addtwonums_hpp */
