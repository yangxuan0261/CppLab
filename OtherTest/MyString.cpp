#include "MyString.h"
#include <cstring>

#include "gtest/gtest.h"

CMyString::CMyString(const char *_str /* = NULL */)
        : mCharArr(nullptr) {
    if (!_str)
        mCharArr = nullptr;
    else {
        mCharArr = new char[strlen(_str) + 1];
        MyStrcpy(mCharArr, _str);
    }
}

// 深拷贝
CMyString::CMyString(const CMyString &_str) {
    if (!_str.mCharArr)
        mCharArr = nullptr;
    else {
        mCharArr = new char[strlen(_str.mCharArr) + 1];
        MyStrcpy(mCharArr, _str.mCharArr);
    }
}

CMyString::~CMyString() {
    if (mCharArr)
        delete[] mCharArr;
}

//CMyString& CMyString::operator=(const CMyString& _str)
//{
//	if (this != &_str)
//	{
//		delete[] mCharArr;
//		if (!_str.mCharArr)
//			mCharArr = nullptr;
//		else
//		{
//			mCharArr = new char[strlen(_str.mCharArr) + 1];
//			MyStrcpy(mCharArr, _str.mCharArr);
//		}
//	}
//	return *this;
//}

CMyString &CMyString::operator=(const CMyString &_str) {
    if (this != &_str) {
        delete[] mCharArr;
        if (!_str.mCharArr)
            mCharArr = nullptr;
        else {
            mCharArr = new char[_str.GetLength() + 1];
            MyStrcpy(mCharArr, _str.mCharArr);
        }
    }
    return *this;
}

CMyString CMyString::operator+(const CMyString &_src) {
    CMyString newStr;
    if (!_src.mCharArr)
        newStr = *this;
    else if (!mCharArr)
        newStr = _src;
    else {
        newStr.mCharArr = new char[strlen(mCharArr) + strlen(_src.mCharArr) + 1];
        MyStrcpy(newStr.mCharArr, mCharArr);
        MyStrcat(newStr.mCharArr, _src.mCharArr);
    }
    return newStr;
}

bool CMyString::operator==(const CMyString &str) {
    assert(mCharArr != NULL);
    if (GetLength() != str.GetLength())
        return false;
    else
        return strcmp(mCharArr, str.mCharArr) ? false : true;
}

char CMyString::operator[](int _index) {
    assert(mCharArr != NULL);
    if (_index >= 0 && _index < strlen(mCharArr))
        return mCharArr[_index];
}

int CMyString::GetLength() const {
    assert(mCharArr != NULL);
    return strlen(mCharArr);
}

int CMyString::FindStrPos(const char *_dst) {
    if (!mCharArr)
        return -1;

    int len = strlen(mCharArr);
    int dstLen = strlen(_dst);

    if (len < dstLen)
        return -1;

    int i = 0;
    for (i = 0; i < len - dstLen; i++) {
        int m = i;
        int j;
        for (j = 0; j < dstLen; j++) {
            if (mCharArr[m] != _dst[j])  //有不匹配字符直接跳出
                break;
            m++;
        }
        if (j == dstLen)  //找到匹配，跳出循环
            break;
    }
    return i < len - dstLen ? i : -1;
}

CMyString CMyString::SubStr(int _offset, int _length) {
    CMyString newStr;
    return newStr;
}

inline const char *CMyString::ToString() const {
    return mCharArr;
}

std::ostream &operator<<(std::ostream &_os, const CMyString &_str) {
    _os << _str.mCharArr;
    return _os;
}

class CMyStringTest : public ::testing::Test {
public:
    CMyStringTest() : Test() {
        std::cout << std::endl;
        std::cout << "------ constructor" << std::endl;
    }

    ~CMyStringTest() {
    }

    virtual void SetUp() {
        Test::SetUp();
    }

    virtual void TearDown() {
        Test::TearDown();
    }
};

namespace MyString {
    TEST_F(CMyStringTest, test_main) {
        CMyString str1("aaa");
        CMyString str2("bbbccc");
        CMyString str3 = str1 + str2;
        std::cout << "--- str1: " << str1 << std::endl;
        std::cout << "--- str2: " << str2 << std::endl;
        std::cout << "--- str3: " << str3 << std::endl;
        std::cout << "str3[3]= " << str3[0] << std::endl;
        std::cout << "str3 length: " << str3.GetLength() << std::endl;

        CMyString str4 = str2;
        std::cout << "str4: " << str4 << std::endl;
        std::cout << (str4 == str2) << std::endl;

        printf("------- str3 tostring: %s\n", str3.ToString());

        int pos = str3.FindStrPos("ab");
        printf("--- pos:%d\n", pos);
    }
}
