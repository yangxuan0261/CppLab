#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <functional>
#include <cstring>

#include "gtest/gtest.h"

using namespace std;

namespace LeetCode {



    // LeetCode第3号问题：无重复字符的最长子串.md
    // https://github.com/MisterBooo/LeetCodeAnimation/blob/master/notes/LeetCode%E7%AC%AC3%E5%8F%B7%E9%97%AE%E9%A2%98%EF%BC%9A%E6%97%A0%E9%87%8D%E5%A4%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E4%B8%B2.md
    TEST(TestLeetCode, test_0003) {
        auto lengthOfLongestSubstring = [&](string s) -> int {
            int freq[256] = {0};
            int l = 0, r = -1; //滑动窗口为s[l...r]
            int res = 0;
            // 整个循环从 l == 0; r == -1 这个空窗口开始
            // 到l == s.size(); r == s.size()-1 这个空窗口截止
            // 在每次循环里逐渐改变窗口, 维护freq, 并记录当前窗口中是否找到了一个新的最优值
            while (l < s.size()) {
                if (r + 1 < s.size() && freq[s[r + 1]] == 0) {
                    r++;
                    freq[s[r]]++;
                } else {   // r已经到头 || freq[s[r+1]] == 1
                    freq[s[l]]--;
                    l++;
                }
                res = max(res, r - l + 1);
            }
            return res;
        };

        // example
        string str1 = "abcabcbb";
        printf("--- len: %d", lengthOfLongestSubstring(str1));
    }
}
