//// extern.cpp : Defines the entry point for the console application.
////
//
//#include "stdlib.h"
//#include <iostream>
//using namespace std;
//
////同一文件中 ，声明在前， 实现在后
//extern int i;  //这里不加extern编译报错，和下面的 int i = 1重定义
//extern void func(); //这里加不加都无所谓，只要后面有实现就ok
//
//int main()//typedef wchar_t     _TCHAR;#define _tmain      wmain
//{
//	func();
//	system("pause");
//	return 0;
//}
//
//
//int i = 1;
//void func()
//{
//	i++;
//	cout << "i = " << i << endl;
//}
//
////上面代码中变量i和函数func在文件末尾定义，
////所以变量需要使用extern关键字告诉编译器，
////变量在别的地方定义。
////extern int i我原来以为extern i就可以，
////结果编译器报错，仔细想下确实应该，
////否则编译器不知道i是什么类型的数据，
////又怎么能判断i = 0是否是一个正确的赋值语句呢？