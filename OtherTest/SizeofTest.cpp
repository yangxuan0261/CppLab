#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>


namespace SizeofTest
{


struct BB
{
	int id;             //[0]....[3]
	double weight;      //[8].....[15]　　　　　　原则１
	short height;      //[16]..[19],总长要为８的整数倍,补齐[20]...[23]　　　　　原则３
};

struct AA
{
	char name[2];     //[0],[1]
	int  id;         //[4]...[7]　　　　　　　　　　原则１
	float score;     //[8]....[11]　　　　
	short grade;    //[12],[13]　　　　　　　　
	BB b;             //[16]......[47]　　　　　　　　　　原则２
};

//字节对齐相关
void testSizeof2()
{
	printf("--- sizeAA:%d, sizeBB:%d\n", sizeof(AA), sizeof(BB)); //AA:40 BB:24
}

void testSizeof()
{
	//前提都是32位编译器编译

	int size = 0;
	size = sizeof(char);
	printf("--- sizeof int = %d\n", size); //1
	size = sizeof(bool);
	printf("--- sizeof bool = %d\n", size);//1
	size = sizeof(short);
	printf("--- sizeof short = %d\n", size);//2
	size = sizeof(int);
	printf("--- sizeof int = %d\n", size);//4
	size = sizeof(long);
	printf("--- sizeof long = %d\n", size);//4
	size = sizeof(long long);
	printf("--- sizeof long long = %d\n", size);//8
	size = sizeof(float);
	printf("--- sizeof float = %d\n", size);//4
	size = sizeof(double);
	printf("--- sizeof double = %d\n", size);//8

	printf("\n");
	int arrInt[10];
	size = sizeof(arrInt);
	printf("--- sizeof arrInt[10] = %d\n", size);//40

	int arrInt2[] = { 1, 2, 3, 4, 5 };
	size = sizeof(arrInt2);
	printf("--- sizeof arrInt2[] = %d\n", size);//20

	int* pInt = arrInt2;
	size = sizeof(pInt);
	printf("--- sizeof pInt = %d\n", size);//4

	//string 里面有 ,_Myres,_Mysize,_Alval,_Myfirstiter 等成员变量 和 一个 char*指针指向字符串数组
	//所以string 的内容无论多长，sizeof(std::string)大小都不会变
	std::string str("321sdfsdfsfsdfsdssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssfsdf");
	str.length();
	size = sizeof(str);
	printf("--- sizeof str = %d\n", size);//28

}

class Door
{
public:
	static int g; //g是在全局静态区，并不会增加Door类的内存大小，也不分布在对象模型中
	int a;
	int b;
};

void testSizeof3()
{
	Door d;
	printf("--- door size:%d\n", sizeof(Door));
	printf("--- g size:%d\n", sizeof(Door::g));
}

void main()
{
	//testSizeof();
	//testSizeof2();
	testSizeof3();
}

} // SizeofTest
