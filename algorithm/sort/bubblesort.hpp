//
//  bubblesort.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/31.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef bubblesort_hpp
#define bubblesort_hpp

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
        class HFBubbleSort
        {
        public:
            typedef std::vector<foundation::HFDataItem<T>> DataList;
            DataList operator()(DataList list);
        };
    }
}

#endif /* bubblesort_hpp */
