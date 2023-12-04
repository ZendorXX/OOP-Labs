#include <gtest/gtest.h>
#include <iostream>
#include "allocator.hpp"
#include "forward_list.hpp"

TEST(ForwardListTest, Push_front) {
    ForwardList<int, Allocator> list;

    list.push_front(4);
    list.push_front(15);
    list.push_front(6);
    
    ASSERT_EQ(list[1], 15);
}

TEST(ForwardListTest, Size) {
    ForwardList<int, Allocator> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);

    ASSERT_EQ(list.size(), 5);
}

TEST(ForwardListTest, Erase_1) {
    ForwardList<int, Allocator> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);

    list.erase(list.begin());

    ASSERT_EQ(list.size(), 4);
}

TEST(ForwardListTest, Erase_2) {
    ForwardList<int, Allocator> list;

    list.push_front(1);
    list.push_front(5);
    list.push_front(6);
    list.push_front(2);

    ForwardList<int, Allocator>::ListIterator it = list.begin();
    ++it;
    list.erase(it);

    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list[0], 2);
    ASSERT_EQ(list[1], 5);
}

TEST(ForwardListTest, Insert) {
    
    ForwardList<int, Allocator> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    ForwardList<int, Allocator>::ListIterator it = list.begin();
    ++it;
    ++it;

    list.insert(it, 9);

    ASSERT_EQ(list[2], 9);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}