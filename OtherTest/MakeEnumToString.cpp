#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#define MakeEm2Str(E)    #E

namespace MakeEnumToString {

    class CMakeEnumToString : public ::testing::Test {
    public:
        CMakeEnumToString() : Test() {
            std::cout << std::endl;
            std::cout << "------ constructor" << std::endl;
        }

        ~CMakeEnumToString() {
        }

        virtual void SetUp() {
            Test::SetUp();
        }

        virtual void TearDown() {
            Test::TearDown();
        }
    };

    enum MyEm {
        ME_Apple = 0,
        ME_Banana,
        ME_Oringe,
    };

    TEST_F(CMakeEnumToString, test_makeEnumToString) {
        std::string str1 = MakeEm2Str(ME_Apple);
        std::string str2 = MakeEm2Str(ME_Banana);
        std::string str3 = MakeEm2Str(ME_Oringe);
        printf("--- str1:%s\n", str1.c_str());
        printf("--- str2:%s\n", str2.c_str());
        printf("--- str3:%s\n", str3.c_str());
    }
}
