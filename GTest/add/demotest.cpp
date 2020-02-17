#include <iostream>
#include "gtest/gtest.h"

class GTestDemo : public ::testing::Test {
private:
    int mNum1 = 123; // 测试框架访问不到

public:
    int mNum2 = 456;

    GTestDemo() : Test() {
        std::cout << "------ constructor" << std::endl;
    }

    ~GTestDemo() {
        std::cout << "--- deconstructor" << std::endl;
    }

    virtual void SetUp() {
        Test::SetUp();
        std::cout << "--- SetUp" << std::endl;
    }

    virtual void TearDown() {
        Test::TearDown();
        std::cout << "--- TearDown" << std::endl;
    }
};

TEST_F(GTestDemo, tc_example_01) {
    std::cout << "tc_example_01: " << mNum2 << std::endl;
}

TEST_F(GTestDemo, tc_example_02) {
    std::cout << "tc_example_02" << std::endl;
}

