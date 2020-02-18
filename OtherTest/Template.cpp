#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

namespace Template {

//------------ test1
    template<typename T = int> //c++98编译通过，c++11编译通过
    class DefClass {
    };

    template<typename T = int>
    //c++98编译失败，c++11编译通过，函数模板的默认模板参数限制被解除
    void DefTempParm() {};

//------------ test2 类模板
    template<typename T1, int i = 0> //类模板的默认模板参数必须遵照“从右往左”的规则，指定默认参数一定要在最右端
    class DefClass1 {
    };

//template <int i = 0, typename T2> //所以这个编译失败
//class DefClass2{};

//------------ test3 函数模板，对于函数模板，在c++11中不需要遵照“从右往左”的规则
    template<typename T1 = int, typename T2>
    void DefFunc1(T1 a, T2 b) {}

    template<int i = 0, typename T2>
    void DefFunc2(T2 a) {}

    TEST(TestTemplate, test_template01) {

    }


//------------ test4
    class Person {
    public:
        //template<int flag, typename T>
        template<int flag, typename T>
        int walk() {
            printf("--- flat:%d\n", flag);
            printf("--- sec type:%s\n", typeid(T).name());
            return 0;
        }

    public:
        std::string mName;
        int mAge;
    };

    TEST(TestTemplate, test_template04) {

        Person *pA = new Person();
        pA->mName = std::string("aaa");
        pA->mAge = 123;
        //pA->run();

        pA->template walk<123, Person>();
    }

}
