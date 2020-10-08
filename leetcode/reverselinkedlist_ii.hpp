//
//  reverselinkedlist_ii.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/11.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#ifndef reverselinkedlist_ii_hpp
#define reverselinkedlist_ii_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/reverse-linked-list-ii
     *
     *  92. 反转链表 II
     *
     *  反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
     *
     *  说明:
     *      1 ≤ m ≤ n ≤ 链表长度。
     *
     *  示例：
     *      输入: 1->2->3->4->5->NULL, m = 2, n = 4
     *      输出: 1->4->3->2->5->NULL
     */
    class HFReverseLinkedListSolutionII : HFSolution
    {
    private:
        struct TestParam {
            ListNode *head;
            int m;
            int n;
            ListNode *expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testReverseBetween();
        
        ListNode *reverseBetween(ListNode *head, int m, int n);
    };
}

#endif /* reverselinkedlist_ii_hpp */
