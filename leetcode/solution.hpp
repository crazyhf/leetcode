//
//  solution.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>

#include "convertutils.hpp"


namespace leetcode
{
    class HFSolution
    {
    protected:
        typedef datastruct::HFListNode<int> ListNode;
        
        ListNode *allocLinkList(std::vector<int> list);
        
        void freeLinkList(ListNode *list);
        
        std::string intVec2Str(const std::vector<int> &intVec);
        
        std::string intVec2Str(const std::vector<std::vector<int>> &intVec);
        
        void printIntVec(const std::vector<int> &intVec);
    };
}

#endif /* solution_hpp */
