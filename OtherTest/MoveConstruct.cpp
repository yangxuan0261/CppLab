#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


namespace MoveConstruct
{

class Human
{
public:
	Human() : mNum(nullptr)
	{
		mNum = new int(123);
		printf("Human 构造\n"); 
	}
	Human(const Human& _h)
	{
		mNum = new int(*_h.mNum);
		printf("Human 拷贝构造\n");
	}
	Human(Human && _h)
	{
		mNum = _h.mNum; //
		_h.mNum = nullptr; //必须将被偷者的指针置空，不然临时对象析构时会释放内存
		printf("Human 移动构造\n");
	}
	virtual ~Human() 
	{
		printf("Human 析构\n");
		if (mNum) delete mNum;
	}
	void show(){ if(mNum) printf("--- num:%d\n", *mNum); }
private:
	int* mNum;
};

Human GetHuman()
{
	Human h1;//构造一个对象
	return h1; //返回时，如果对象实现了移动构造(默认没实现)，则会移动构造外部值
}				//如果没有移动构造（默认实现拷贝构造 - 位拷贝），拷贝构造外部值
				//位拷贝只是将里面的指针复制过来，还是指向同个内存，所以临时变量被析构后，
				//外部值的成员就指向了被释放过的内存地址，生命周期结束后将再次析构造成崩溃

Human GetHuman2()
{
	return Human(); //直接构造给外部值，不会产生临时变量，也不会调用自定义拷贝构造或者移动构造，只会进行位拷贝，谨慎
}

void testMoveConstruct()
{
	Human h2 = GetHuman();//如果没有移动构造，将会调用拷贝构造，又涉及到深拷贝，但还是释放临时对象中产生的内存
	h2.show();			//而移动构造直接使用临时对象中产生的内存，减少了一次new和delete的操作
	system("pause");	
}
/*
Human 构造
Human 移动构造
Human 析构
--- num:123
请按任意键继续. . .
Human 析构
*/

void testRValueRef1()
{
	Human h2 = GetHuman2(); //因为直接构造给外部值作为临时变量，且这里是右值引用，所以生命周期随h2结束而结束
	h2.show();
	system("pause");
	//h2 = GetHuman2(); //GetHuman2按位拷贝给h2，导致临时变量被析构后h2.num会指向被析构过的内存，h2生命周期结束再次delete num，崩
	system("pause");
}
/*
Human 构造
--- num:123
请按任意键继续. . .
请按任意键继续. . .
Human 析构
*/


//形参是右值引用，所以必须为临时变量这种，
void AcceptRValueRef(Human&& _h)
{
	system("pause"); //1
	Human h2 = std::move(_h); //这里将再次移动构造一个对象h2，待_h(临时对象)和h2对象的生命周期结束(这个方法结束)后都会析构
	system("pause");//2
}

void testRValueRef2()
{
	AcceptRValueRef(GetHuman()); //GetHuman里会构造一个对象，然后移动构造一个临时对象作为形参传入
	system("pause");//3
}
/*
Human 构造
Human 移动构造
Human 析构
请按任意键继续. . . //1
Human 移动构造
请按任意键继续. . . //2
Human 析构
Human 析构
请按任意键继续. . . //3
*/

void testRValueRef3()
{
	//int&& num = 1 + 1; //右值引用 123 或 1+1的结果2 等临时变量，因为这临时变量在这行代码结束后就会销毁
	int&& num = 123; //通过右值引用让其生命得以延续，随着num的结束而结束
	num += 123;

	printf("--- num:%d\n", num); 
}

void main()
{
	//testMoveConstruct();
	//testRValueRef1();
	//testRValueRef2();
	//testRValueRef3();
}
} // MoveConstruct
