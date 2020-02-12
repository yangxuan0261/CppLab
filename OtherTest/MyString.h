#ifndef __MyString_H__
#define __MyString_H__

#include<iostream>
#include <assert.h>

inline char *MyStrcpy(char *dst, const char *src) {
    assert((dst != NULL) && (src != NULL));
    char *retCharArr = dst;
    while ((*dst++ = *src++) != '\0');
    return retCharArr;
}

inline char *MyStrcat(char *_dst, const char *_src) {
    char *cp = _dst;
    while (*cp)
        cp++;
    while (*cp++ = *_src++);
    return (_dst);
}

class CMyString {
public:
    CMyString(const char *_str = NULL);

    CMyString(const CMyString &_str); // �������������mCharr��ָ��ͬ���ڴ棻
    virtual ~CMyString();

    CMyString &operator=(const CMyString &_str); // ��ֵ
    CMyString operator+(const CMyString &_str); // �ַ�ƴ��
    bool operator==(const CMyString &_str); // ����ж�
    char operator[](int _index); // ���� �ַ�
    int GetLength() const;// ����
    int FindStrPos(const char *_dst); //�����ַ���λ��
    CMyString SubStr(int _offset, int _length);

    const char *ToString() const;

    friend std::ostream &operator<<(std::ostream &_os, const CMyString &_str); // �����

private:
    char *mCharArr;
};

#endif // !__MyString_H__

