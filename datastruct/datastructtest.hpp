//
//  datastructtest.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/9/10.
//  Copyright © 2020 Haven·Lin. All rights reserved.
//

#ifndef datastructtest_hpp
#define datastructtest_hpp

#include "linklist.hpp"
#include "sqlist.hpp"

#include <vector>


namespace leetcode
{
    namespace datastruct
    {
        namespace test
        {
            class HFDataStructTest
            {
            private:
                struct TestParam {
                    std::vector<int> nums;
                };
                std::vector<TestParam> testParams();
                
            public:
                void testLinkList1();
                void testLinkList2();
            };
        }
    }
}

#endif /* datastructtest_hpp */
