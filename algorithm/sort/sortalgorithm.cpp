//
//  sortalgorithm.cpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/20.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "sortalgorithm.hpp"


namespace algorithm
{
    namespace sort
    {
        template <typename T>
        class HFSortAlgorithm<foundation::HFDataItem<T>>
        {
        public:
            typedef foundation::HFDataItem<T> DataItem;
        };
    }
}
