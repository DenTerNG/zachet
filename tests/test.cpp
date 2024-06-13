#include "a_b.hpp"

#include <gtest/gtest.h>

TEST(ABTest, TestF1AgainstSomefunc) {
    A a;
    B b;
    int testNumber = 15; // Число, которое делится на 5

    int resFromF1 = a.f1(testNumber);
    int resFromSomefunc = b.somefunc(testNumber);

    ASSERT_EQ(resFromF1, resFromSomefunc);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
