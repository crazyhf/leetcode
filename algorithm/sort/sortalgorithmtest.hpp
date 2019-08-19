//
//  sortalgorithmtest.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/19.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef sortalgorithmtest_hpp
#define sortalgorithmtest_hpp

#include "bubblesort.hpp"
#include "quicksort.hpp"


namespace algorithm
{
    namespace sort
    {
        namespace test
        {
            class HFSortAlgorithmTest
            {
            private:
                struct TestParam {
                    std::vector<int> nums;
                    std::vector<int> expect;
                };
                std::vector<TestParam> testParams();
                
            public:
                void testQuickSort();
                
                void testBubbleSort();
            };
        }
    }
}

#endif /* sortalgorithmtest_hpp */