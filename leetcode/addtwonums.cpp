//
//  addtwonums.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/20.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "addtwonums.hpp"

using namespace std;
using namespace leetcode;


vector<HFAddTwoNumsSolution::TestParam> HFAddTwoNumsSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .l1=allocLinkList({2, 4, 3}),
                         .l2=allocLinkList({5, 6, 4}),
                         .expect=allocLinkList({7, 0, 8})
    });
    paramVec.push_back({ .l1=allocLinkList({5}),
                         .l2=allocLinkList({5}),
                         .expect=allocLinkList({0, 1})
    });
    return paramVec;
}

void HFAddTwoNumsSolution::testAddTwoNumbers()
{
    cout << "===============================================" << endl
         << "HFAddTwoNumsSolution (2. 两数相加) :" << endl
         << "给出两个非空的链表用来表示两个非负的整数。" << endl
         << "其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。" << endl
         << "如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        ListNode *result = addTwoNumbers(param.l1, param.l2);
        cout << endl << "Input : " << foundation::linkList2Str(param.l1) << endl
             << "        " << foundation::linkList2Str(param.l2) << endl
             << "Output: " << foundation::linkList2Str(result) << endl
             << "Expect: " << foundation::linkList2Str(param.expect) << endl;
        freeLinkList(param.l1);
        freeLinkList(param.l2);
        freeLinkList(result);
        freeLinkList(param.expect);
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

HFAddTwoNumsSolution::ListNode *HFAddTwoNumsSolution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = nullptr, *current = nullptr;
    int carry = 0;
    while (l1 || l2) {
        if (nullptr == result) {
            current = result = new ListNode(0);
        } else {
            current = current->next = new ListNode(0);
        }
        if (l1 && l2) {
            current->val = l1->val + l2->val + carry;
            l1 = l1->next; l2 = l2->next;
        } else if (l1) {
            current->val = l1->val + carry;
            l1 = l1->next;
        } else {
            current->val = l2->val + carry;
            l2 = l2->next;
        }
        if (current->val >= 10) { current->val -= 10; carry = 1; }
        else { carry = 0; }
    }
    if (carry > 0) { current->next = new ListNode(carry); }
    return result;
}
