#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

// Контейнер: односторонний список

#include <iostream>
#include <exception>
#include <iterator> 
#include "allocator.hpp"

template <class T>
struct Item {
    T value;
    Item<T>* next;

    T& get(size_t index) {
        if (index == 0) {
            return value;
        }
        if (next) {
            return next->get(--index);
        }
        throw std::logic_error("Out of bounds");
    }
};

template <class T, template <class> class Allocator = std::allocator>
class ForwardList {
    private:
        Allocator<Item<T>> allocator;
        Item<T>* head;
        size_t sz;

    public:
        using value_type = T;
        class ListIterator {
            private:
                ForwardList& list;
                friend class List;
            public:
                size_t index;
                
                using difference_type = int;
                using value_type = ForwardList::value_type;
                using reference = ForwardList::value_type& ;
                using pointer = ForwardList::value_type*;
                using iterator_category = std::forward_iterator_tag;

                ListIterator(ForwardList<T, Allocator> &l, int i) : list(l), index(i) {}

                ListIterator& operator++() {
                    ++index;
                    return *this;
                }

                reference operator*() {
                    return list[index];
                }

                pointer operator->() {
                    return &list[index];
                }

                bool operator!=(const ListIterator &other) const {
                    if (index != other.index) {
                        return true;
                    }
                    if (&list != &(other.list)) {
                        return true;
                    }
                    return false;
                }

                bool operator==(const ListIterator& other) const{
                    if (index != other.index) {
                        return false;
                    }
                    if (&list != &(other.list)) { 
                        return false;
                    }
                    return true;
                }
        };

        class ConstListIterator{
            private:
                const ForwardList& list;
                friend class List;
            public:
                size_t  index;
                using difference_type = int ;
                using value_type = ForwardList::value_type;
                using reference = const ForwardList::value_type& ;
                using pointer = const ForwardList::value_type*;
                using iterator_category = std::forward_iterator_tag;

                ConstListIterator(const ForwardList<T, Allocator> &l,int i) : list(l), index(i){
                } 

                ConstListIterator& operator++(){
                    ++index;
                    return *this;
                }

                reference operator*(){
                    return list[index];
                }

                pointer operator->(){
                    return &list[index];
                }

                bool operator!=(const ListIterator& other) const{
                    if(index!=other.index) return true;
                    if(&list!=&(other.list)) return true;
                    return false;
                }

                bool operator==(const ListIterator& other) const{
                    if(index!=other.index) return false;
                    if(&list!=&(other.list)) return false;
                    return true;
                }
        };

    public:
        ForwardList() {
            sz = 0;
        }

        void push_front(const T &value) {
            Item<T>* new_item = allocator.allocate(1);
            new_item->value = value;
            new_item->next = head;
            head = new_item; 
            ++sz;
        }

        T& operator[] (size_t index) {
            return head->get(index);
        }

        size_t size() {
            return sz;
        }

        bool empty() {
            return sz == 0;
        }

        ~ForwardList() {
            while(!this->empty()) {
                Item<T>* curr = head;
                head = head->next;
                --sz;
                allocator.deallocate(curr, 1);
            }
            sz = 0;
        }

        ListIterator erase(ListIterator iter) {
            if (iter.index == 0) {
                Item<T>* curr = head;
                head = head->next;
                --sz;
                allocator.deallocate(curr, 1);
            } 
            else {
                size_t curr_index = 0;
                Item<T>* curr = head;
                while (curr_index != iter.index - 1) {
                    curr = curr->next;
                    ++curr_index;
                }

                Item<T>* who_to_erase = curr->next;
                curr->next = who_to_erase->next;
                --sz;
                allocator.deallocate(who_to_erase, 1);
            }
            
            if (iter.index < size()) {
                return iter;
            }
            return ListIterator(*this, size());
        }

        ListIterator insert (ListIterator iter, const T& value){
            if (iter.index == 0) {
                push_front(value);
            } 
            else {
                size_t curr_index = 0;
                Item<T>* curr = head;
                while (curr_index != iter.index - 1) {
                    curr = curr->next;
                    ++curr_index;
                }

                Item<T>* new_item = allocator.allocate(1);
                new_item->value = value;

                new_item->next = curr->next;
                curr->next = new_item;
                
                ++sz;
            }
            
            if (iter.index < size()) {
                return iter;
            }
            return ListIterator(*this, size());
        }

        ListIterator begin(){
            return ListIterator(*this, 0);
        }

        ListIterator end(){
            return ListIterator(*this, size());
        }

        ConstListIterator cbegin(){
            return ConstListIterator(*this, 0);
        }

        ConstListIterator cend(){
            return ConstListIterator(*this, size());
        }
};

#endif