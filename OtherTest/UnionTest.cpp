#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace UnionTest {
	void test222()
	{
		union testasd
		{
			char mark;
			long num;
			float score;
		}a;

		// cout<<a<<endl; // wrong
		a.mark = 'b';
		cout << a.mark << endl; // 输出'b'
		cout << a.num << endl; // 98 字符'b'的ACSII值
		cout << a.score << endl; // 输出错误值

		a.num = 10;
		cout << a.mark << endl; // 输出换行 非常感谢suxin同学的指正
		cout << a.num << endl; // 输出10
		cout << a.score << endl; // 输出错误值

		a.score = 10.01;
		cout << a.mark << endl; // 输出空
		cout << a.num << endl; // 输出错误值
		cout << a.score << endl; // 输出10
	}

	void testUnion()
	{
		union UBoy {
			int age;
			short num;
		} bo;

		bo.age = 5;

		struct SGirl
		{
			int age;
			short num;
		} gi;

		printf("size u:%d\n", sizeof(bo));
		printf("size u:%d\n", sizeof(gi));
		printf("size u:%d\n", bo.age);
	}

	void testLittleOrBigEndian()
	{
		union w
		{
			int a;
			char b;
		} c;
		c.a = 1;
		printf("ptr address:%x\n", &c.b);
		if (c.b == 1)
			printf("is little endian\n");
		else
			printf("is big endian\n");
	}

	void main() {
		//testUnion();
		//test222();
		testLittleOrBigEndian();
	}
};
