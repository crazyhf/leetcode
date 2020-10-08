//
//  reverselinkedlist.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/13.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#include "reverselinkedlist.hpp"

using namespace std;
using namespace leetcode;


vector<HFReverseLinkedListSolution::TestParam> HFReverseLinkedListSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .head=allocLinkList({1, 2, 3, 4, 5}),
                         .expect=allocLinkList({5, 4, 3, 2, 1})
    });
    return paramVec;
}

void HFReverseLinkedListSolution::testReverseList()
{
    cout << "===============================================" << endl
         << "HFReverseLinkedListSolution (206. 反转链表) :" << endl
         << "反转一个单链表。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        cout << endl << "Input : " << foundation::linkList2Str(param.head) << endl;
        ListNode *result = reverseList(param.head);
        cout << "Output: " << foundation::linkList2Str(result) << endl
             << "Expect: " << foundation::linkList2Str(param.expect) << endl;
        freeLinkList(result);
        freeLinkList(param.expect);
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

HFReverseLinkedListSolution::ListNode *HFReverseLinkedListSolution::reverseList(ListNode *head)
{
    if (!head || !(head->next)) { return head; }
    
    ListNode *current = head->next, *prev = head;
    while (current) {
        ListNode *tmp = current->next;
        current->next = prev;
        prev = current;
        current = tmp;
    }
    head->next = nullptr;
    return prev;
}
