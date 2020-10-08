//
//  reverselinkedlist.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/13.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#ifndef reverselinkedlist_hpp
#define reverselinkedlist_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/reverse-linked-list
     *
     *  206. 反转链表
     *
     *  反转一个单链表。
     *
     *  示例：
     *      输入: 1->2->3->4->5->NULL
     *      输出: 5->4->3->2->1->NULL
     *
     *  进阶:
     *      你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
     */
    class HFReverseLinkedListSolution : HFSolution
    {
    private:
        struct TestParam {
            ListNode *head;
            ListNode *expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testReverseList();
        
        ListNode *reverseList(ListNode *head);
    };
}

#endif /* reverselinkedlist_hpp */
