#ifndef __AUXLIB_H__
#define __AUXLIB_H__

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <utility>
#include <list>
#include <queue>
#include <functional>
#include <time.h>
#include <random>
#include <unordered_map>
#include <cstring>

using namespace std;


// 辅助工具
namespace auxlib {
    typedef char Element;

    class CBTNode {
    public:
        Element data;
        CBTNode *left;
        CBTNode *right;
    };

    // 构建二叉树, 注意这里是 指针的引用, 因为在里面有给指针 new 对象
    void buildBinTree(CBTNode *&node, Element data[], int &myindex);

    // 前序遍历二叉树
    void preOrderTraverse(CBTNode *root);
}

#endif //__AUXLIB_H__
