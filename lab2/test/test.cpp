#include <gtest/gtest.h>
#include "seven.hpp"

TEST(test_01, add_tests) {
    Seven a1 ("534021");
    Seven b1 ("102346");
    Seven c1 = a1 + b1;
    Seven d1("636400");
    ASSERT_TRUE(c1 == d1);

    Seven a2 ("534021");
    Seven b2 ("6252");
    Seven c2 = a2 + b2;
    Seven d2("543303");
    ASSERT_TRUE(c2 == d2);

    Seven a3 ("236");
    Seven b3 ("26");
    Seven c3 = a3 + b3;
    Seven d3("265");
    ASSERT_TRUE(c3 == d3);

    Seven a4 ("2");
    Seven b4 ("4");
    Seven c4 = a4 + b4;
    Seven d4("6");
    ASSERT_TRUE(c4 == d4);

    Seven a5 ("6");
    Seven b5 ("1");
    Seven c5 = a5 + b5;
    Seven d5("10");
    ASSERT_TRUE(c5 == d5);

    Seven a6 ("6");
    Seven b6 ("6");
    Seven c6 = a6 + b6;
    Seven d6("15");
    ASSERT_TRUE(c6 == d6);

    Seven a7 ("6000");
    Seven b7 ("6000");
    Seven c7 = a7 + b7;
    Seven d7 ("15000");
    ASSERT_TRUE(c7 == d7);
}

TEST(test_07, diff_test) {
    Seven a7 ("6000");
    Seven b7 ("6000");
    Seven c7 = a7 - b7;
    Seven d7 ("0");
    ASSERT_TRUE(c7 == d7);
}

TEST(test_06, diff_test) {
    Seven a6 ("15");
    Seven b6 ("6");
    Seven c6 = a6 - b6;
    Seven d6("6");
    ASSERT_TRUE(c6 == d6);
}

TEST(test_05, diff_test) {
    Seven a5 ("10");
    Seven b5 ("1");
    Seven c5 = a5 - b5;
    Seven d5("6");
    ASSERT_TRUE(c5 == d5);
}

TEST(test_04, diff_test) {
    Seven a4 ("4");
    Seven b4 ("2");
    Seven c4 = a4 - b4;
    Seven d4("2");
    ASSERT_TRUE(c4 == d4);
}

TEST(test_03, diff_test) {
    Seven a3 ("265");
    Seven b3 ("236");
    Seven c3 = a3 - b3;
    Seven d3("26");
    ASSERT_TRUE(c3 == d3);
}

TEST(test_02, diff_test) {
    Seven a2 ("543303");
    Seven b2 ("6252");
    Seven c2 = a2 - b2;
    Seven d2("534021");
    ASSERT_TRUE(c2 == d2);
}

TEST(test_01, diff_test) {
    Seven a1 ("534021");
    Seven b1 ("102346");
    Seven c1 = a1 - b1;
    Seven d1("431342");
    ASSERT_TRUE(c1 == d1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}