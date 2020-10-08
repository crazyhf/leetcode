//
//  reverselinkedlist_ii.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/11.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#include "reverselinkedlist_ii.hpp"

using namespace std;
using namespace leetcode;


vector<HFReverseLinkedListSolutionII::TestParam> HFReverseLinkedListSolutionII::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .head=allocLinkList({1, 2, 3, 4, 5}),
                         .m=2, .n=4,
                         .expect=allocLinkList({1, 4, 3, 2, 5})
    });
    paramVec.push_back({ .head=allocLinkList({3, 5}),
                         .m=1, .n=2,
                         .expect=allocLinkList({5, 3})
    });
    return paramVec;
}

void HFReverseLinkedListSolutionII::testReverseBetween()
{
    cout << "===============================================" << endl
         << "HFReverseLinkedListSolutionII (92. 反转链表 II) :" << endl
         << "反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        cout << endl << "Input : " << foundation::linkList2Str(param.head)
             << " m = " << param.m << ", n = " << param.n << endl;
        ListNode *result = reverseBetween(param.head, param.m, param.n);
        cout << "Output: " << foundation::linkList2Str(result) << endl
             << "Expect: " << foundation::linkList2Str(param.expect) << endl;
        freeLinkList(result);
        freeLinkList(param.expect);
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

HFReverseLinkedListSolutionII::ListNode *HFReverseLinkedListSolutionII::reverseBetween(ListNode *head, int m, int n)
{
    do {
        if (!head || !(head->next) || n <= m) { break; }
        
        ListNode *head1 = nullptr, *head2 = head, *prev = head;
        
        int count = 1;
        for (; count < m && head2; count++) {
            head1 = head2;
            prev  = head2 = head2->next;
        }
        
        if (!head2) { break; }
        
        head2 = head2->next;
        count++;
        for (; count <= n && head2; count++) {
            ListNode *tmp = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = tmp;
        }
        
        if (head1) {
            head1->next->next = head2;
            head1->next = prev;
        } else {
            head->next = head2;
            head = prev;
        }
    } while (false);
    return head;
}
