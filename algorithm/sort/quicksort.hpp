//
//  quicksort.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/31.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef quicksort_hpp
#define quicksort_hpp

#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>

#include "dataitem.hpp"

namespace algorithm
{
    namespace sort
    {
        template <typename T>
        class HFQuickSort
        {
        public:
            typedef foundation::HFDataItem<T> DataItem;
            typedef std::vector<DataItem> DataList;
            
        private:
            int partition(DataList &list, int begin, int end)
            {
                DataItem key = list[begin];
                return 0;
            }
            
        public:
            void operator()(DataList &list)
            {
                ;
            }
        };
    }
}


#endif /* quicksort_hpp */
