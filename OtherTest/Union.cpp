#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "gtest/gtest.h"

using namespace std;

namespace Union {

    class CUnion : public ::testing::Test {
    public:
        CUnion() : Test() {
            std::cout << std::endl;
            std::cout << "------ constructor" << std::endl;
        }

        ~CUnion() {
        }

        virtual void SetUp() {
            Test::SetUp();
        }

        virtual void TearDown() {
            Test::TearDown();
        }
    };

    TEST_F(CUnion, test_actVal) {
        union testasd {
            char mark;
            long num;
            float score;
        } a;

        a.mark = 'a';
        cout << a.mark << endl;
        cout << a.num << endl;
        cout << a.score << endl;

        std::cout << "" << std::endl;
        a.num = 10;
        cout << a.mark << endl;
        cout << a.num << endl;
        cout << a.score << endl;

        std::cout << "" << std::endl;
        a.score = 10.01;
        cout << a.mark << endl;
        cout << a.num << endl;
        cout << a.score << endl;
    }

    TEST_F(CUnion, test_size) {
        union UBoy {
            int age;
            short num;
        } bo;

        bo.age = 5;

        struct SGirl {
            int age;
            short num;
        } gi;

        printf("size u:%d\n", sizeof(bo)); // 4
        printf("size u:%d\n", sizeof(gi)); // 8
        printf("size u:%d\n", bo.age); // 5
    }

    TEST_F(CUnion, test_littleOrBigEndian) {
        union w {
            int a;
            char b;
        } c;
        c.a = 1;
        printf("ptr address:%p\n", &c.b);
        if (c.b == 1)
            printf("is little endian\n");
        else
            printf("is big endian\n");
    }
}
