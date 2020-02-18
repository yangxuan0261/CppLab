#include <iostream>
#include "gtest/gtest.h"

class GTestDemo : public ::testing::Test {
private:
    int mNum1 = 123; // 测试框架访问不到

public:
    int mNum2 = 456;

    GTestDemo() : Test() {
        std::cout << std::endl;
        std::cout << "------ constructor" << std::endl; // 换行, 为了好看点
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

    void hello() {
        std::cout << "--- hello" << std::endl;
    }
};

TEST_F(GTestDemo, tc_example_01) {
    int a = 1;
    hello();
    std::cout << "tc_example_01: " << mNum2 << std::endl;
}

TEST_F(GTestDemo, tc_example_02) {
    std::cout << "tc_example_02" << std::endl;
    EXPECT_TRUE(true) << "--- diagnostic message";
}

