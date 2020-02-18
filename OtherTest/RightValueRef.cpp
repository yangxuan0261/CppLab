#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "gtest/gtest.h"

namespace RightValueRef {

    class CRightValueRef : public ::testing::Test {
    public:
        CRightValueRef() : Test() {
            std::cout << std::endl;
            std::cout << "------ constructor" << std::endl;
        }

        ~CRightValueRef() {
        }

        virtual void SetUp() {
            Test::SetUp();
        }

        virtual void TearDown() {
            Test::TearDown();
        }
    };

    inline int f(int _arg) { return 50 * _arg; }

    TEST_F(CRightValueRef, test_rightValueRef) {
        int a = 10;
        int &&b = 20;
        int &&c = 30 + a;
        int &&d = f(c);

        std::cout << "--- a value and address: " << a << ", " << &a << std::endl;
        std::cout << "--- b value and address: " << b << ", " << &b << std::endl;
        std::cout << "--- c value and address: " << c << ", " << &c << std::endl;
        std::cout << "--- d value and address: " << d << ", " << &d << std::endl;
    }
}
