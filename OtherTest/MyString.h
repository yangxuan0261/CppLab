#ifndef __MyString_H__
#define __MyString_H__

#include<iostream> 
#include <assert.h>

inline char* MyStrcpy(char *dst, const char *src)
{
	assert((dst != NULL) && (src != NULL));
	char* retCharArr = dst;
	while ((*dst++ = *src++) != '\0');
	return retCharArr;
}

inline char* MyStrcat(char* _dst, const char* _src)
{
	char * cp = _dst;
	while (*cp)
		cp++; 
	while (*cp++ = *_src++);
	return(_dst);
}

class CMyString
{
public:
	CMyString(const char* _str = NULL);
	CMyString(const CMyString& _str); // 必须深拷贝，否者mCharr会指向同个内存；
	virtual ~CMyString();

	CMyString& operator=(const CMyString& _str); // 赋值 
	CMyString operator+(const CMyString& _str); // 字符拼接   
	bool operator==(const CMyString& _str); // 相等判断  
	char operator[](int _index); // 索引 字符
	int GetLength() const;// 长度  
	int FindStrPos(const char* _dst); //查找字符串位置
	CMyString SubStr(int _offset, int _length);
	const char* ToString() const; 
	friend std::ostream& operator<<(std::ostream& _os, const CMyString& _str); // 输出流
	
private:
	char* mCharArr;
};
#endif // !__MyString_H__

