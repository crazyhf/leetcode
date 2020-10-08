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
            HFListNode *prev;
            HFListNode *next;
            
            HFListNode(typename HFDataStruct<T>::Elem elem,
                       HFListNode *prevNode = nullptr,
                       HFListNode *nextNode = nullptr)
                       : val(elem), prev(prevNode), next(nextNode) {}
            
            HFListNode(HFListNode *prevNode = nullptr,
                       HFListNode *nextNode = nullptr)
                       : prev(prevNode), next(nextNode) {}
        };
        
        //template <typename T>
        //using HFLinkList = HFListNode<T> *;
    
        //template <typename T>
        //using HFLinkList = typename HFListNode<T>::HFLinkList;
        
        template <typename T>
        class HFListIterator
        {
        public:
            typedef HFListNode<T> Node;
            
            HFListIterator(Node *ptr) : _ptr(ptr) {}
            
            Node& operator*() { return *_ptr; }
            const Node& operator*() const { return *_ptr; }
            
            Node* operator->() { return _ptr; }
            const Node* operator->() const { return _ptr; }
            
            HFListIterator& operator++()
            {
                _ptr = _ptr->next; return *this;
            }
            HFListIterator& operator--()
            {
                _ptr = _ptr->prev; return *this;
            }
            
            bool operator==(const HFListIterator &ite) const { return _ptr == ite._ptr; }
            bool operator!=(const HFListIterator &ite) const { return _ptr != ite._ptr; }
            
        private:
            Node *_ptr;
        };
        
        /**
         *  https://www.programiz.com/dsa/linked-list
         *
         *  链表
         */
        template <typename T>
        class HFLinkList
        {
        public:
            typedef HFListIterator<T> Iterator;
            typedef HFListNode<T> Node;
            
            HFLinkList() { _reset(); }
            ~HFLinkList() { clear(); }
            
            HFLinkList(const HFLinkList& list) { _reset(); _copy(list); }
            HFLinkList& operator=(const HFLinkList& list)
            {
                _reset(); _copy(list); return *this;
            }
            
            Iterator begin() const { return Iterator(_head); }
            Iterator end() const   { return Iterator(_tail); }
            
            void deleteFirst()
            {
                if (!isEmpty()) {
                    Node *cur   = _head;
                    _head       = _head->next;
                    _head->prev = &_empty_node;
                    delete cur;
                    _len--;
                }
            }
            void deleteLast()
            {
                if (!isEmpty()) {
                    Node *cur       = _tail->prev;
                    _tail->prev     = cur->prev;
                    cur->prev->next = _tail;
                    delete cur;
                    _len--;
                }
            }
            void clear()
            {
                Node *cur = _head;
                while (cur != _tail) {
                    Node *next = cur->next;
                    delete cur;
                    cur = next;
                }
                _reset();
            }
            
            void append(T value)
            {
                Node *node  = new Node(value);
                node->next  = _tail;
                node->prev  = _tail->prev;
                
                _tail->prev = node;
                if (_head == _tail) { _head = node; }
                else { node->prev->next = node; }
                
                _len++;
            }
            
            size_t length() { return _len; }
            bool  isEmpty() { return 0 == _len; }
            
        private:
            void _reset()
            {
                _empty_node.prev = &_empty_node;
                _empty_node.next = &_empty_node;
                
                _head = &_empty_node;
                _tail = &_empty_node;
                _len  = 0;
            }
            void _copy(const HFLinkList &list)
            {
                clear();
                
                Iterator endIte = list.end();
                for (Iterator ite = list.begin(); ite != endIte; ++ite) {
                    append(ite->val);
                }
            }
            
        private:
            Node   _empty_node;
            
            Node  *_head;
            Node  *_tail;
            size_t _len;
        };
    }
}

#endif /* linklist_hpp */
