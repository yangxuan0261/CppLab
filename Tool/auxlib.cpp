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
#include <cstdio>
#include <string>
#include <cassert>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include "Tool/auxlib.h"

namespace auxlib {

    void buildBinTree(CBTNode *&root, Element data[], int &myindex) {
        Element e = data[myindex++];
        // printf("--- myindex: %d\n", myindex);
        if (e == '#') {
            root = NULL;
        } else {
            root = new CBTNode();
            root->data = e;
            buildBinTree(root->left, data, myindex);  //递归构建左子树
            buildBinTree(root->right, data, myindex);  //递归构建右子树
        }
    }

    void preOrderTraverse(CBTNode *root) {
        if (root != NULL) {
            printf("%c ", root->data); // 前序遍历
            preOrderTraverse(root->left);
            // printf("%c ", root->left); // 中序遍历
            preOrderTraverse(root->right);
            // printf("%c ", root->right); // 后序遍历
        }
    }

}
