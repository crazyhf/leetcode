//
//  main.m
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "dataitem.hpp"

#include "sortalgorithmtest.hpp"

#include "towsum.hpp"
#include "addtwonums.hpp"
#include "mergeary.hpp"
#include "numtrees.hpp"
#include "longestconsecutivelist.hpp"
#include "intersectary.hpp"
#include "addtwonums_ii.hpp"

using namespace leetcode;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        algorithm::sort::test::HFSortAlgorithmTest().testQuickSort1();
        algorithm::sort::test::HFSortAlgorithmTest().testQuickSort2();
        algorithm::sort::test::HFSortAlgorithmTest().testBubbleSort1();
        algorithm::sort::test::HFSortAlgorithmTest().testBubbleSort2();
        
        HFTwoSumSolution().testTwoSum();
        HFAddTwoNumsSolution().testAddTwoNumbers();
        HFMergeArySolution().testMerge();
        HFNumTreesSolution().testNumTrees();
        HFLongestConsecutiveListSolution().testLongestConsecutive();
        HFIntersectArySolution().testIntersection();
        HFAddTwoNumsSolutionII().testAddTwoNumbers();
        
        foundation::HFNumberItem item1(2);
        
        item1.boolVal();
    }
    return 0;
}
