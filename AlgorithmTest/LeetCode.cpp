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

    // LeetCode 第 26 号问题：删除排序数组中的重复项
    // https://github.com/MisterBooo/LeetCodeAnimation/blob/master/notes/LeetCode%E7%AC%AC26%E5%8F%B7%E9%97%AE%E9%A2%98%EF%BC%9A%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9.md
    TEST(TestLeetCode, test_0026) {
        auto removeDuplicates = [&](vector<int> &nums) -> int {
            if (nums.empty()) return 0;
            int pre = 0, cur = 0, n = nums.size();
            while (cur < n) {
                if (nums[pre] == nums[cur]) {
                    cur++;
                } else {
                    ++pre;
                    nums[pre] = nums[cur];
                    cur++;
                }
            }
            return pre + 1;
        };

        // example
        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int len = removeDuplicates(nums);
        printf("--- len: %d\n", len);
        for (int i = 0; i < len; ++i) {
            printf("--- idx: %d, val: %d\n", i, nums[i]);
        }
    }
}
