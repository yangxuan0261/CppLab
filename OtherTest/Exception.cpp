
#include "gtest/gtest.h"

namespace Exception {

    class CException : public ::testing::Test {
    public:
        CException() : Test() {
            std::cout << std::endl;
            std::cout << "------ constructor" << std::endl;
        }

        ~CException() {
        }

        virtual void SetUp() {
            Test::SetUp();
        }

        virtual void TearDown() {
            Test::TearDown();
        }
    };

    TEST_F(CException, test_string) {

    }
}
