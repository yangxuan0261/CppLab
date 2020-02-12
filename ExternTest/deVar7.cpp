#include <stdio.h>
#include "stdlib.h"
#include <iostream>

//extern "C"
//{
//
//	int i = 100;
//
//	void func()
//	{
//		printf("--- %d\n", i++);
//	}
//}

//因为入口函数在.c文件中，采用的c编译器编译运行，所以如果c中使用外部实现的方式，且在cpp中
//那么cpp中的所有被c文件中声明extern的变量或方法，都需要声明为 extern "C"，表明cpp中的变量或方法用c编译器去编译
//此时, 除了需要使用extern "C"声明编译的时候采用C方式编译外，
//.cpp文件中的代码可以按照C++方式编写，例如
//
//devVar.cpp按照下面方式写，也是正确的。
//hello world



extern "C" int i = 100;
extern "C" void func()
{
		printf("--- %d\n", i++);
}
