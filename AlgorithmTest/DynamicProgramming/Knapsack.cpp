// 贪心算法
#include<iostream>

#include "gtest/gtest.h"

#include <iostream>
#include <fstream>

using namespace std;

// 0 1 背包问题
// https://www.cnblogs.com/labuladong/p/13927944.html


namespace Knapsack {


    // 遍历方式
    /*
    第二步要明确 dp 数组的定义。
    首先看看刚才找到的「状态」，有两个，也就是说我们需要一个二维 dp 数组。
    dp[i][w] 的定义如下：对于前 i 个物品，当前背包的容量为 w，这种情况下可以装的最大价值是 dp[i][w]。
    比如说，如果 dp[3][5] = 6，其含义为：对于给定的一系列物品中，若只对前 3 个物品进行选择，当背包容量为 5 时，最多可以装下的价值为 6。
     */
    int knapsack(int W, int N, vector<int> &wt, vector<int> &val) {
        // base case 已初始化
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int w = 1; w <= W; w++) {
                if (w - wt[i - 1] < 0) {
                    // 这种情况下只能选择不装入背包
                    dp[i][w] = dp[i - 1][w];
                } else {
                    // 装入或者不装入背包，择优
                    dp[i][w] = max(dp[i - 1][w - wt[i - 1]] + val[i - 1],
                                   dp[i - 1][w]);
                }
            }
        }

        // 打印出来 二维表
        for (auto i: dp) {
            for (auto w:i) {
                printf(", %3d", w);
            }
            cout << endl;
        }

        return dp[N][W];
    }


    vector<vector<int>> maxBag;

    // 递归方式, 参考 金矿模型 MaxGold.cpp
    // N 是 物品的索引值, 所以边界值是 0
    int MaxKnapsack(int W, int N, vector<int> const &wt, vector<int> const &val) {
        printf("--- MaxKnapsack, W: %d, N: %d\n", W, N);

        int retMax;

        if (maxBag[W][N] != -1) { // 缓存复用, 避免对此求解
            retMax = maxBag[W][N];
        } else if (N == 0) { // 边界处理
            if (W >= wt[N]) {
                retMax = val[N];
            } else {
                retMax = 0;
            }
        } else if (W >= wt[N]) { // 最优子结构
            retMax = max(MaxKnapsack(W - wt[N], N - 1, wt, val) + val[N], // 放入背包
                         MaxKnapsack(W, N - 1, wt, val)); // 不放入背包
        } else { // 最优子结构
            retMax = MaxKnapsack(W, N - 1, wt, val);
        }

        maxBag[W][N] = retMax; // 缓存
        printf("--- maxBag, W: %d, N: %d, retMax: %d\n", W, N, retMax);
        return retMax;
    }

    TEST(TestKnapsack, test_001) {
        vector<int> wt = {2, 1, 3};
        vector<int> val = {4, 2, 3};
        int N = wt.size(); // 物品数量
        int W = 4;

        printf("--- res: %d\n", knapsack(W, N, wt, val)); // 6
    }

    TEST(TestKnapsack, test_002) {
        vector<int> wt = {2, 1, 3};
        vector<int> val = {4, 2, 3};
        int N = wt.size(); // 物品数量
        int W = 10;

        maxBag = vector<vector<int>>(W + 1, vector<int>(N, -1));

        printf("--- knapsack: %d\n", knapsack(W, N, wt, val)); // 6
        printf("--- MaxKnapsack: %d\n", MaxKnapsack(W, N - 1, wt, val)); // 6

        // 打印出来 二维表
        for (auto i: maxBag) {
            for (auto w:i) {
                printf(", %3d", w);
            }
            cout << endl;
        }
    }
}
