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


namespace algorithm
{
    namespace sort
    {
        template <typename T>
        class HFBubbleSort
        {
        public:
            typedef std::vector<typename HFSortAlgorithm<T>::DataItem> DataList;
            
            DataList operator()(DataList list);
        };
    }
}

#endif /* bubblesort_hpp */
