#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "A.h"

class MockA {
public:
    MOCK_METHOD0(getInstance, A*());
    MOCK_METHOD0(AConstructor, void());
};

// Глобальная переменная для mock-объекта
MockA* mockA = nullptr;

// Переопределение метода getInstance для использования mock-объекта
A* A::getInstance() {
    if (!mockA) {
        static A instance;  // Создание единственного экземпляра
        return &instance;
    }
    return mockA->getInstance();
}

// Переопределение конструктора для использования mock-объекта
A::A() {
    if (mockA) {
        mockA->AConstructor();
    }
}

TEST(ATest, GetInstanceCalledOnce) {
    MockA mock;
    mockA = &mock;

    EXPECT_CALL(mock, AConstructor()).Times(1);
    EXPECT_CALL(mock, getInstance()).Times(2).WillRepeatedly(::testing::Return(reinterpret_cast<A*>(1)));

    A* pa1 = A::getInstance();
    A* pa2 = A::getInstance();

    mockA = nullptr;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

