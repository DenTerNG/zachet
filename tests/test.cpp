#include <gtest/gtest.h>
#include "A.h"

TEST(ATest, GetInstanceCalledOnce) {
    A* pa1 = A::getInstance();
    A* pa2 = A::getInstance();

    EXPECT_EQ(pa1, pa2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
