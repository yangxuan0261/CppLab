#include <iostream>
#include "add/add.h"
#include "gtest/gtest.h" // 引入 gtest

TEST(TestCase, test1) {
    std::cout << "---- test1 hello world" << std::endl;
    ASSERT_EQ(12, add(4, 8));
}

TEST(TestCase, test2) {
    std::cout << "---- test2 hello world 111" << std::endl;
//    ASSERT_TRUE(false) << "--- err: wolegequ"; // 将中断执行
//    EXPECT_TRUE(false) << "--- err: wolegequ"; // 不中断执行, 会报用例测试失败
    std::cout << "---- test2 hello world 222" << std::endl;
}

TEST(TestCase, test3) {
    std::cout << "---- test3 hello world" << std::endl;
    EXPECT_EQ(3, add(1, 2));
}

GTEST_API_ int main(int argc, char **argv) {
    system("chcp 65001");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
