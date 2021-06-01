// 贪心算法
#include<iostream>

#include "gtest/gtest.h"

#include <iostream>
#include <fstream>

using namespace std;

// 国王和金矿问题 (0 1 背包)
// https://www.cnblogs.com/SDJL/archive/2008/08/22/1274312.html
// https://www.zhihu.com/question/39948290/answer/663769511

namespace MaxGold {

    const int max_n = 100;//程序支持的最多金矿数
    const int max_people = 10000;//程序支持的最多人数

    int n;//金矿数
    int peopleTotal;//可以用于挖金子的人数
    int peopleNeed[max_n];//每座金矿需要的人数
    int gold[max_n];//每座金矿能够挖出来的金子数
    int maxGold[max_people][max_n];//maxGold[i][j]保存了i个人挖前j个金矿能够得到的最大金子数，等于-1时表示未知

    //初始化数据
    void init() {
        ifstream inputFile("beibao.in");
        inputFile >> peopleTotal >> n;
        for (int i = 0; i < n; i++) {
            inputFile >> peopleNeed[i] >> gold[i];
            printf("--- people: %d, gold: %d\n", peopleNeed[i], gold[i]);
        }
        inputFile.close();

        for (int i = 0; i <= peopleTotal; i++)
            for (int j = 0; j < n; j++)
                maxGold[i][j] = -1;//等于-1时表示未知 [对应动态规划中的“做备忘录”]

    }

    //获得在仅有people个人和前mineNum个金矿时能够得到的最大金子数，注意“前多少个”也是从0开始编号的
    int GetMaxGold(int people, int mineNum) {
        printf("--- GetMaxGold, people: %d, mineIdx: %d\n", people, mineNum);

        //申明返回的最大金子数
        int retMaxGold;

        //如果这个问题曾经计算过  [对应动态规划中的“做备忘录”]
        if (maxGold[people][mineNum] != -1) {
            //获得保存起来的值
            printf("--- maxGold[people][mineIdx] != -1 111, people: %d, mineNum: %d\n", people, mineNum);
            retMaxGold = maxGold[people][mineNum];
        } else if (mineNum == 0)//如果仅有一个金矿时 [对应动态规划中的“边界”]
        {
            //当给出的人数足够开采这座金矿
            if (people >= peopleNeed[mineNum]) {
                //得到的最大值就是这座金矿的金子数
                printf("--- people >= peopleNeed[mineIdx] 111, people: %d, mineNum: %d\n", people, mineNum);
                retMaxGold = gold[mineNum];
            } else//否则这唯一的一座金矿也不能开采
            {
                //得到的最大值为0个金子
                printf("--- people >= peopleNeed[mineIdx] 222, people: %d, mineNum: %d\n", people, mineNum);
                retMaxGold = 0;
            }
        } else if (people >= peopleNeed[mineNum])//如果给出的人够开采这座金矿 [对应动态规划中的“最优子结构”]
        {
            //考虑开采与不开采两种情况，取最大值
            printf("--- people >= peopleNeed[mineIdx], people: %d, mineNum: %d\n", people, mineNum);
            retMaxGold = max(GetMaxGold(people - peopleNeed[mineNum], mineNum - 1) + gold[mineNum],
                             GetMaxGold(people, mineNum - 1));
        } else//否则给出的人不够开采这座金矿 [对应动态规划中的“最优子结构”]
        {
            //仅考虑不开采的情况
            printf("--- maxGold[people][mineIdx] != -1 222, people: %d, mineNum: %d\n", people, mineNum);
            retMaxGold = GetMaxGold(people, mineNum - 1);
        }

        //做备忘录
        maxGold[people][mineNum] = retMaxGold;
        printf("--- people: %d, mineNum: %d\n", people, mineNum);
        return retMaxGold;
    }

    // https://www.cnblogs.com/SDJL/archive/2008/08/22/1274312.html
    TEST(TestMaxGold, test_001) {
        // 将文件 拷贝到 cmake-build-debug 下就可以运行了

        //初始化数据
        init();
        //输出给定peopleTotal个人和n个金矿能够获得的最大金子数，再次提醒编号从0开始，所以最后一个金矿编号为n-1
        cout << GetMaxGold(peopleTotal, n - 1);
    }
}
