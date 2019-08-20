//
//  convertutils.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/19.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef convertutils_hpp
#define convertutils_hpp

#include <string>
#include <vector>

#include "sqlist.hpp"
#include "linklist.hpp"


namespace foundation
{
    std::string intVec2Str(const std::vector<int> &intVec);
    
    std::string dataList2Str(const std::vector<HFDataItem<HFNumberItem>> &dataList);
    
    std::string linkList2Str(leetcode::datastruct::HFListNode<int> *list);
    
    std::vector<HFDataItem<HFNumberItem>> intVec2DataList(const std::vector<int> &intVec);
}

#endif /* convertutils_hpp */
