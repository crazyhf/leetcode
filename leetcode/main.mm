//
//  main.m
//  leetcode
//
//  Created by linhuafeng on 2019/7/30.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "dataitem.hpp"

#include "datastructtest.hpp"
#include "sortalgorithmtest.hpp"

#include "towsum.hpp"
#include "addtwonums.hpp"
#include "longestsubstrnorepeatchar.hpp"
#include "midoftwosortedary.hpp"
#include "longestpalindromicsubstr.hpp"
#include "reverseinteger.hpp"
#include "spiralmatrix.hpp"
#include "mergeary.hpp"
#include "reverselinkedlist_ii.hpp"
#include "numtrees.hpp"
#include "longestconsecutivelist.hpp"
#include "reverselinkedlist.hpp"
#include "intersectary.hpp"
#include "addtwonums_ii.hpp"

using namespace leetcode;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        datastruct::test::HFDataStructTest().testLinkList1();
        datastruct::test::HFDataStructTest().testLinkList2();
        
        algorithm::sort::test::HFSortAlgorithmTest().testQuickSort1();
        algorithm::sort::test::HFSortAlgorithmTest().testQuickSort2();
        algorithm::sort::test::HFSortAlgorithmTest().testBubbleSort1();
        algorithm::sort::test::HFSortAlgorithmTest().testBubbleSort2();
        
        HFTwoSumSolution().testTwoSum();
        HFAddTwoNumsSolution().testAddTwoNumbers();
        HFLongestSubstrNoRepeatCharSolution().testLenOfLongestSubstr();
        HFMidOfTwoSortedArySolution().testFindMidSortedArys();
        HFLongestPalindromicSubstrSolution().testLongestPalindrome();
        HFReverseIntegerSolution().testReverse();
        HFSpiralMatrixSolution().testSpiralOrder();
        HFMergeArySolution().testMerge();
        HFReverseLinkedListSolutionII().testReverseBetween();
        HFNumTreesSolution().testNumTrees();
        HFLongestConsecutiveListSolution().testLongestConsecutive();
        HFReverseLinkedListSolution().testReverseList();
        HFIntersectArySolution().testIntersection();
        HFAddTwoNumsSolutionII().testAddTwoNumbers();
        
        foundation::HFNumberItem item1(2);
        
        item1.boolVal();
    }
    return 0;
}
