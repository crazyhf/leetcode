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


namespace leetcode
{
    class HFSolution
    {
    protected:
        std::string intVec2Str(const std::vector<int> &intVec);
        
        void printIntVec(const std::vector<int> &intVec);
    };
}

#endif /* solution_hpp */
