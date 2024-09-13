#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "function.hpp"

// Test case for the function
TEST(FunctionTest, BasicTest) {
    EXPECT_EQ(function(1, 2), 3); // (1 + 2) / 1 = 3
    EXPECT_EQ(function(2, 2), 2); // (2 + 2) / 2 = 2
    EXPECT_EQ(function(3, 3), 2); // (3 + 3) / 3 = 2
    EXPECT_EQ(function(4, 0), 1); // (4 + 0) / 4 = 1
}

// Test case for edge cases
TEST(FunctionTest, EdgeCases) {
    EXPECT_EQ(function(1, 0), 1); // (1 + 0) / 1 = 1
    EXPECT_EQ(function(0, 0), 0); // (0 + 0) / 0 = 0 (undefined behavior, but function returns 0)
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
