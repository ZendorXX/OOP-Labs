#include <gtest/gtest.h>
#include "function.cpp"

TEST(test_01, labs_tests) {
    ASSERT_TRUE(eliminate_unset_bits("1101010101010101") == 511);
    ASSERT_TRUE(eliminate_unset_bits("110101010101010") == 255);
    ASSERT_TRUE(eliminate_unset_bits("111") == 7);
    ASSERT_TRUE(eliminate_unset_bits("1000000") == 1);
    ASSERT_TRUE(eliminate_unset_bits("000") == 0);
}

TEST(test_02, error_tests) {
    ASSERT_TRUE(eliminate_unset_bits("") == -1);
    ASSERT_TRUE(eliminate_unset_bits("11034394") == -1);
    ASSERT_TRUE(eliminate_unset_bits("refgvggt") == -1);
    ASSERT_TRUE(eliminate_unset_bits("10110101101013") == -1);
    ASSERT_TRUE(eliminate_unset_bits("00101010ew") == -1);
}

TEST(test_03, boundary_tests) {
    ASSERT_TRUE(eliminate_unset_bits("0") == 0);
    ASSERT_TRUE(eliminate_unset_bits("000000") == 0);
    ASSERT_TRUE(eliminate_unset_bits("0000") == 0);
    ASSERT_TRUE(eliminate_unset_bits("111111111111111111111111111111111111111111111111111111111111111") == 9223372036854775807);
    ASSERT_TRUE(eliminate_unset_bits("11111111111101110111111111010011110111110111111110111111111111111111111") == 9223372036854775807);
}

TEST(test_04, random_tests) {
    ASSERT_TRUE(eliminate_unset_bits("0101") == 3);
    ASSERT_TRUE(eliminate_unset_bits("100101001") == 15);
    ASSERT_TRUE(eliminate_unset_bits("111011101110011") == 2047);
    ASSERT_TRUE(eliminate_unset_bits("0000000000000000001") == 1);
    ASSERT_TRUE(eliminate_unset_bits("101011010100001011101111100101") == 131071);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}