#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include "gtest/gtest.h"

/*
 * 参考:
 * - 正则表达式简介及在C++11中的简单使用 - https://blog.csdn.net/wolegequ/article/details/54835571
*/

namespace Regex {

    TEST(TestRegex, test_match) {
        std::string pattern{"\\d{3}-\\d{8}|\\d{4}-\\d{7}"}; // fixed telephone
        std::regex re(pattern);

        std::vector<std::string> str{
                "010-12345678",
                "0319-9876543",
                "021-123456789",
        };

        /* std::regex_match:
            判断一个正则表达式(参数re)是否匹配整个字符序列str,它主要用于验证文本
            注意，这个正则表达式必须匹配被分析串的全部，否则返回false;如果整个序列被成功匹配，返回true
        */

        for (auto tmp : str) {
            bool ret = std::regex_match(tmp, re);
            if (ret) {
                fprintf(stdout, "--- %s, can match\n", tmp.c_str());
            } else {
                fprintf(stdout, "--- %s, can not match\n", tmp.c_str());
            }
        }
    }

    TEST(TestRegex, test_search) {
        std::string pattern{"http|hppts://\\w*$"}; // url
        std::regex re(pattern);

        std::vector<std::string> str{
                "http://blog.csdn.net/wolegequ",
                "https://github.com/wolegequ",
                "abcd://124.456",
                "abcd https://github.com/wolegequ 123",
        };

        /* std::regex_search:
            类似于regex_match,但它不要求整个字符序列完全匹配
            可以用regex_search来查找输入中的一个子序列，该子序列匹配正则表达式re
        */

        for (auto tmp : str) {
            bool ret = std::regex_search(tmp, re);
            if (ret) {
                fprintf(stdout, "--- %s, can search\n", tmp.c_str());
            } else {
                fprintf(stdout, "--- %s, can not search\n", tmp.c_str());
            }
        }

        std::string var = "first second third forth";

        std::cout << "----- smatch" << std::endl;
        const std::regex r("(.*) (.*) (.*) (.*)");
        std::smatch sm;

        if (regex_search(var, sm, r)) {
            for (int i = 0; i < sm.size(); i++) { // 捕获到的组, 0 是 匹配串, 之后是组元素
                std::cout << sm[i] << std::endl;
            }
        }
    }

    TEST(TestRegex, test_search_all01) {
        std::cout << "----- match all" << std::endl;
        std::regex exp("(\\b\\S*\\b)");
        std::smatch res;
        std::string str2 = "first second third forth";

        while (std::regex_search(str2, res, exp)) {
            std::cout << res[0] << std::endl; // res[0] 是 匹配串, 如果表达式中还有捕获, 那么 0 之后的就是捕获值
            str2 = res.suffix();
        }
    }

    TEST(TestRegex, test_search_all02) {
        std::string pattern{"([a-zA-z]+:)//[^\\s]*"}; // url
        std::regex re(pattern);

        std::string str = "my csdn blog addr is: http://blog.csdn.net/wolegequ , my github addr is: https://github.com/wolegequ ";
        std::smatch res;
        while (std::regex_search(str, res, re)) {
            for (auto x : res) // 遍历出 0: 匹配串, 和 0 之后的捕获值
                std::cout << x << " ";
            std::cout << std::endl;
            str = res.suffix();
        }
    }

    TEST(TestRegex, test_replace01) {
        std::string pattern{"\\d{18}|\\d{17}X"}; // id card
        std::regex re(pattern);

        std::vector<std::string> str{
                "123456789012345678",
                "abcd123456789012345678efgh",
                "abcdefbg",
                "12345678901234567X"
        };

        std::string fmt{"********"};

        /* std::regex_replace:
            在整个字符序列中查找正则表达式re的所有匹配
            这个算法每次成功匹配后，就根据参数fmt对匹配字符串进行替换
        */

        for (auto tmp : str) {
            std::string ret = std::regex_replace(tmp, re, fmt);
            fprintf(stdout, "src: %s, dst: %s\n", tmp.c_str(), ret.c_str());
        }
    }

    TEST(TestRegex, test_replace02) {
        // reference: http://www.cplusplus.com/reference/regex/regex_replace/
        std::string s("there is a subsequence in the string\n");
        std::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

        // using string/c-string (3) version:
        std::cout << std::regex_replace(s, e, "$1-$2"); // there is a sub-sequence in the string // 使用捕获到的值

        // using range/c-string (6) version:
        std::string result;
        std::regex_replace(std::back_inserter(result), s.begin(), s.end(), e,
                           "$2"); // there is a sequence in the string
        std::cout << result;

        // with flags:
        std::cout << std::regex_replace(s, e, "$1 and $2"); // there is a sub and sequence in the string
        std::cout << std::regex_replace(s, e, "$1 and $2", std::regex_constants::format_no_copy); // sub and sequence

        std::cout << std::endl;
    }
}
