//
//  bubblesort.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/31.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef bubblesort_hpp
#define bubblesort_hpp

#include "sortalgorithm.hpp"


namespace leetcode
{
    namespace algorithm
    {
        namespace sort
        {
            /**
             *  https://www.programiz.com/dsa/bubble-sort
             *
             *  冒泡排序
             */
            template <typename T>
            class HFBubbleSort
            {
            public:
                typedef std::vector<T> List;
                
            public:
                static void sort(List &list)
                {
                    for (size_t idx = 1; idx < list.size(); idx++) {
                        for (size_t jdx = 0; jdx < list.size() - idx; jdx++) {
                            if (list[jdx] > list[jdx + 1]) {
                                T item = list[jdx + 1];
                                list[jdx + 1] = list[jdx];
                                list[jdx] = item;
                            }
                        }
                    }
                }
            };
        }
    }
}

#endif /* bubblesort_hpp */
