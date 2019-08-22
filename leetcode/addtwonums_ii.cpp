//
//  addtwonums_ii.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/20.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "addtwonums_ii.hpp"

using namespace std;
using namespace leetcode;


HFAddTwoNumsSolutionII::ListNode *HFAddTwoNumsSolutionII::allocLinkList(std::vector<int> list)
{
    ListNode *head = nullptr, *current = nullptr;
    for (size_t idx = 0; idx < list.size(); idx++) {
        if (nullptr == head) {
            current = head = new ListNode(list[idx]);
        } else {
            current = current->next = new ListNode(list[idx]);
        }
    }
    return head;
}

void HFAddTwoNumsSolutionII::freeLinkList(ListNode *list)
{
    while (list) {
        ListNode *current = list;
        list = list->next;
        delete current;
    }
}

vector<HFAddTwoNumsSolutionII::TestParam> HFAddTwoNumsSolutionII::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .l1=allocLinkList({7, 2, 4, 3}),
                         .l2=allocLinkList({5, 6, 4}),
                         .expect=allocLinkList({7, 8, 0, 7})
    });
    paramVec.push_back({ .l1=allocLinkList({9, 9, 9}),
                         .l2=allocLinkList({9, 9}),
                         .expect=allocLinkList({1, 0, 9, 8})
    });
    paramVec.push_back({ .l1=allocLinkList({9, 9, 0, 9}),
                         .l2=allocLinkList({9, 9, 9}),
                         .expect=allocLinkList({1, 0, 9, 0, 8})
    });
    paramVec.push_back({ .l1=allocLinkList({5}),
                         .l2=allocLinkList({5}),
                         .expect=allocLinkList({1, 0})
    });
    return paramVec;
}

void HFAddTwoNumsSolutionII::testAddTwoNumbers()
{
    cout << "===============================================" << endl
         << "HFAddTwoNumsSolutionII :" << endl
         << "给定两个非空链表来代表两个非负整数。" << endl
         << "数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。" << endl;
    
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

HFAddTwoNumsSolutionII::ListNode *HFAddTwoNumsSolutionII::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int len1 = 0, len2 = 0;
    ListNode *node1 = l1, *node2 = l2;
    while (node1 || node2) {
        if (node1) { len1++; node1 = node1->next;}
        if (node2) { len2++; node2 = node2->next;}
    }
    
    ListNode *result = nullptr, *current = nullptr, *prev = nullptr;
    int idx = (len1 > len2 ? len1 : len2);
    while (idx) {
        if (nullptr == result) {
            current = result = new ListNode(0);
        } else {
            current = current->next = new ListNode(0);
        }
        if (idx <= len1) {
            current->val += l1->val; l1 = l1->next;
        }
        if (idx <= len2) {
            current->val += l2->val; l2 = l2->next;
        }
        if (current->val >= 10) {
            current->val -= 10;
            if (prev) {
                prev->val += 1;
            } else {
                prev = new ListNode(1);
                prev->next = result;
                result = prev;
            }
            while (prev->next != current) {
                prev = prev->next;
                prev->val = 0;
            }
        }
        if (current->val < 9) { prev = current; }
        idx--;
    }
    return result;
}
