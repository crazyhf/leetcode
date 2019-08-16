//
//  main.m
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "dataitem.hpp"

#include "towsum.hpp"
#include "numtrees.hpp"
#include "mergeary.hpp"
#include "longestconsecutivelist.hpp"


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        leetcode::HFTwoSumSolution().testTwoSum();
        leetcode::HFNumTreesSolution().testNumTrees();
        leetcode::HFMergeArySolution().testMerge();
        leetcode::HFLongestConsecutiveListSolution().testLongestConsecutive();
        
        foundation::HFNumberItem item1(2);
        
        item1.boolVal();
    }
    return 0;
}
