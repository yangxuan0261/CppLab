#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include "ClassTemplate.h"
#include <cstring>

#include "gtest/gtest.h"

#include "Tool/util.h"

using namespace std;

namespace BaseTest {

    TEST(TestBase, test_string) {
        float _num = 123.45f;
        char buff[12];
        sprintf(buff, "%0.2f", _num);
        printf("--- buff: %s\n", buff);

        string str = "asdwa";
        str = buff;
        printf("--- str: %s\n", str.c_str());
        int len = str.length();
        printf("--- len: %d\n", len);

        string listFilePath = "helloworld/aaa";
        if (listFilePath.find('/') != string::npos) {
            listFilePath = listFilePath.substr(0, listFilePath.rfind('/') + 1);
            printf("--- substr: %s\n", listFilePath.c_str());
        } else
            printf("no find /\n");

        std::string path = "aaa/vvv/bbb.c";
        int lastpos = path.find_last_of("/");
        printf("--- lastpos: %d\n", lastpos);
        path = path.substr(0, lastpos + 1);
        printf("--- destPath: %s\n", path.c_str());
    }

    TEST(TestBase, test_stringSubstr) {
        std::string s("456789");
        int len = s.length();
        for (size_t i = 0; i < len; i++) {


            int a = atoi(s.substr(i, 1).c_str());
            printf("--- num:%d\n", a);
        }
    }

    TEST(TestBase, test_arrayPtr01) {
        // 得到数组的最后一个数 - 使用指向数组的指针来完成
        printf("--- 得到数组的最后一个数的趣味实现 \n");

        const int MAXN = 8;
        int a[MAXN] = {1, 2, 4, 8, 16, 32, 64, 128};

        //a的地址往后偏移1位，取得另一个地址这是指向的是位置的东西，只需将这个地址往前偏移1位，就能取得正确的数组的最后一位
        int *p = (int *) (&a + 1);  //&a 是一个指针，指向大小为4的数组 int(*)[MAXN]
        printf("--- %d\n", *((int *) p - 1)); //为128

        //a的首地址往后偏移7位，再取值
        //int num = *((int*)(&a) + 7);
        //printf("--- num:%d\n", num);
    }

    TEST(TestBase, test_arrayPtr02) {
        auto func = [](int *arr, int row, int col) {
            int counter = 0;
            for (size_t i = 0; i < row; i++) {
                for (size_t j = 0; j < col; j++) {
                    int num = *((int *) arr + counter++);
                    printf("%d ", num);
                }
                printf("\n");
            }
        };


        int arr[5][10];
        int counter = 1;
        for (size_t i = 0; i < 5; i++) {
            for (size_t j = 0; j < 10; j++) {
                arr[i][j] = counter++;
            }
        }

        int *tmp = &(*arr)[0];
        func(tmp, 5, 10);


        int num = *((int *) (&arr) + 25);
        printf("--- num:%d\n", num);
    }

    const char *testFuncName() {
        return __FUNCTION__; //返回方法名
    }

    struct testAAA {
        testAAA() : name(__FUNCTION__) {
        }

        const char *name;
    };

    TEST(TestBase, test_funcName) {
        const char *charr = testFuncName();
        printf("--- func name:%s\n", charr); // --- func name:testFuncName

        testAAA t1;
        printf("--- test name:%s\n", t1.name); // --- test name:testAAA
    }

    TEST(TestBase, test_lognlong) {
        auto num = 234123123ll;
        printf("--- num:%lld\n", num);
    }


    TEST(TestBase, test_getVec) {
        auto GetVec = []() -> std::vector<int> { return {1, 2, 3}; };
        std::vector<int> &&v = GetVec();
        for (int a : v)
            printf("---a:%d\n", a);
    }

    TEST(TestBase, test_stringR) {
        std::string tmp = " 吃饭了";
        std::string str = R"(hello \n \t 好的 world)" " ##早上好" + tmp;
        std::cout << str << std::endl;
    }

    static void parseUTF8(const std::string &str, std::vector<std::string> &ret) {
        int l = str.length();
        ret.clear();
        for (int p = 0; p < l;) {
            int size = 0;
            unsigned char c = str[p];
            if (c < 0x80) {
                size = 1;
            } else if (c < 0xc2) {
                size = 2;
            } else if (c < 0xe0) {
                size = 2;
            } else if (c < 0xf0) {
                size = 3;
            } else if (c < 0xf8) {
                size = 4;
            } else if (c < 0xfc) {
                size = 5;
            } else if (c < 0xfe) {
                size = 6;
            } else
                size = 7;
            std::string temp = "";
            temp = str.substr(p, size);
            ret.push_back(temp);
            p += size;
        }
    }

    static std::string subUTF8(const std::string &str, int from, int to) {
        if (from > to) return "";

        if (str.length() < to) return "";

        std::vector<std::string> vstr;
        parseUTF8(str, vstr);
        to = to > vstr.size() ? vstr.size() : to;

        std::vector<std::string>::iterator iter = vstr.begin();
        std::string res;
        std::string result;
        for (iter = (vstr.begin() + from); iter != (vstr.begin() + to); iter++) {
            res += *iter;
        }
        return res;
    }

    static std::string stringReplace(const std::string &input,
                                     const std::string &find,
                                     const std::string &replaceWith) {
        std::string strOut(input);
        int curPos = 0;

        int pos;
        while ((pos = strOut.find(find, curPos)) != -1) {
            strOut.replace(pos, find.size(), replaceWith);
            curPos = pos + replaceWith.size();
        }

        return strOut;
    }

    TEST(TestBase, test_subUTF8) {
        std::string str = "asd注\n\n\n册阿斯顿qwe";
        str = stringReplace(str, "\n", "");
        std::string tmp = subUTF8(str.c_str(), 0, 6);
        std::string tmp2 = subUTF8(str.c_str(), 6, str.length() - 1);
        printf("--- %s\n", tmp.c_str());
        printf("--- %s\n", tmp2.c_str());
    }

    TEST(TestBase, test_strlen) {
        const char *mystr = "hello";
        printf("len=%d\n", strlen(mystr));

        printf("len2=%d\n", strlen(mystr + 3));
        printf("len2=%d\n", strlen(mystr + 5)); //越界到 \0 字符, 因此长度为 0
    }

    TEST(TestBase, test_list) {
        std::list<std::string> ml;
        ml.push_back("aaaa");
        ml.push_back("bbb");
        ml.push_back("ccc");
        while (!ml.empty()) {
            printf("--- val:%s\n", (*ml.begin()).c_str());
            ml.pop_front();
        }
    }

    TEST(TestBase, test_tool) {
        vector<int> numVt = {111, 222, 333, 444, 555};
        Tool::printVec(numVt);

        std::cout << std::endl;
        vector<string> strVt = {"aaa", "bbb", "ccc", "ddd"};
        Tool::printVec(strVt);
    }


    class CActor {
    public:
        void say();

        string name;
    };

    void CActor::say() {
        printf("--- %s say\n", this->name.c_str());
    }

    TEST(TestBase, test_copy) {
        CActor *a1 = new CActor();
        a1->name = "hello";
        a1->say();

        CActor a2 = *a1; // 复制拷贝
        a2.name = "world";

        a1->say();
    }

}
