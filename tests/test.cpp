#include <gtest/gtest.h>
#include <gtest/gmock.h>

class A {
public:
    static A* getInstance();

private:
    A();
    static A* instance;
};

A* A::instance = nullptr;

A::A() {
    std::cout << "construct A" << std::endl;
}

A* A::getInstance() {
    std::cout << "get A" << std::endl;
    if (!instance) {
        instance = new A;
    }
    return instance;
}

class MockA {
public:
    MOCK_METHOD0(getInstance, A*());
    MOCK_METHOD0(AConstructor, void());
};

MockA* mockA;

A* A::getInstance() {
    if (!mockA) {
        return nullptr;
    }
    return mockA->getInstance();
}

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
