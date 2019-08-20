//
//  quicksort.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/7/31.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef quicksort_hpp
#define quicksort_hpp

#include "sortalgorithm.hpp"


namespace algorithm
{
    namespace sort
    {
        template <typename T>
        class HFQuickSort
        {
        public:
            typedef std::vector<typename HFSortAlgorithm<T>::DataItem> DataList;
            
        private:
            static int partition(DataList &list, int low, int high)
            {
                typename HFSortAlgorithm<T>::DataItem key = list[low];
                while (low < high) {
                    while (low < high && list[high] >= key) high--;
                    list[low] = list[high];
                    while (low < high && list[low] <= key) low++;
                    list[high] = list[low];
                }
                list[low] = key;
                return low;
            }
            
            static void sort(DataList &list, int low, int high)
            {
                if (low < 0 || low >= list.size()
                    || high < 0 || high >= list.size() || low >= high) return;
                
                int idx = partition(list, low, high);
                sort(list, low, idx - 1);
                sort(list, idx + 1, high);
            }
            
        public:
            static void sort(DataList &list)
            {
                sort(list, 0, (int)(list.size() - 1));
            }
        };
    }
}


#endif /* quicksort_hpp */
