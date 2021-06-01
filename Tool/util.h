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

using namespace std;

namespace tool {

//    template<typename T>
//    void printVec(std::vector<T> &vt);

    template<typename T>
    void printVec(std::vector<T> &vt) {
        int len = vt.size();
        for (int i = 0; i < len; ++i) {
            std::cout << "--- idx: " << i << ", val: " << vt[i] << std::endl;
        }
    }

    // https://cloud.tencent.com/developer/ask/37475
    template<typename... Args>
    std::string string_format(const std::string &format, Args... args) {
        size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format.c_str(), args ...);
        return string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }

    // https://cloud.tencent.com/developer/ask/37475
    template<typename... Args>
    std::string string_format2(const char *format, Args... args) {
        int length = std::snprintf(nullptr, 0, format, args...);
        assert(length >= 0);

        char *buf = new char[length + 1];
        std::snprintf(buf, length + 1, format, args...);

        std::string str(buf);
        delete[] buf;
        return std::move(str);
    }
}
#endif //__UTIL_H__
