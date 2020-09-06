#ifndef __UTIL_H__
#define __UTIL_H__

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

namespace Tool {

//    template<typename T>
//    void printVec(std::vector<T> &vt);

    template<typename T>
    void printVec(std::vector<T> &vt) {
        int len = vt.size();
        for (int i = 0; i < len; ++i) {
            std::cout << "--- idx: " << i << ", val: " << vt[i] << std::endl;
        }
    }
}
#endif //__UTIL_H__
