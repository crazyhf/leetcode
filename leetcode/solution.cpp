//
//  solution.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "solution.hpp"

using namespace std;
using namespace leetcode;


HFSolution::ListNode *HFSolution::allocLinkList(std::vector<int> list)
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

void HFSolution::freeLinkList(ListNode *list)
{
    while (list) {
        ListNode *current = list;
        list = list->next;
        delete current;
    }
}

string HFSolution::intVec2Str(const vector<int> &intVec)
{
    return foundation::intVec2Str(intVec);
}

string HFSolution::intVec2Str(const vector<vector<int>> &intVec)
{
    return foundation::intVec2Str(intVec);
}

void HFSolution::printIntVec(const vector<int> &intVec)
{
    cout << foundation::intVec2Str(intVec);
}
