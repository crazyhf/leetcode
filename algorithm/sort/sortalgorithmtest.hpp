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


namespace leetcode
{
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
                    void testQuickSort1();
                    void testQuickSort2();
                    
                    void testBubbleSort1();
                    void testBubbleSort2();
                };
            }
        }
    }
}

#endif /* sortalgorithmtest_hpp */
