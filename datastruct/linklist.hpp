//
//  linklist.hpp
//  leetcode
//
//  Created by linhuafeng on 2019/8/20.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef linklist_hpp
#define linklist_hpp

#include "datastruct.hpp"


namespace leetcode
{
    namespace datastruct
    {
        template <typename T>
        struct HFListNode
        {
            //typedef HFListNode *HFLinkList;
            
            typename HFDataStruct<T>::Elem val;
            HFListNode *next;
            
            HFListNode(typename HFDataStruct<T>::Elem elem) : val(elem), next(nullptr) {}
        };
        
        //template <typename T>
        //using HFLinkList = HFListNode<T> *;
        
        //template <typename T>
        //using HFLinkList = typename HFListNode<T>::HFLinkList;
        
        template <typename T>
        class HFLinkList
        {
        private:
            HFListNode<T> *head;
        };
    }
}

#endif /* linklist_hpp */
