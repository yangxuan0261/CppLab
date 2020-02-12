#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

//---------------------------------------test1
using namespace std;


namespace UsingTest {
    


class Base
{
public:
	void menfcn()
	{
		cout << "Base function" << endl;
	}

	void menfcn(int n)
	{
		cout << "Base function with int" << endl;
	}
//private: 
//	void menfcn(std::string _name) {}//会让基类using时报不可访问的错
};

class Derived : private Base
{
public:
	using Base::menfcn;//using声明只能指定一个名字，不能带形参表，且基类的该函数不能有私有版本，否则编译报错
						//using父类方法，主要是用来实现可以在子类实例中调用到父类的重载版本
	int menfcn(int num)
	{
		cout << "Derived function with int : "<< num << endl;
		return num;
	}
};

/*
“隐藏”是指派生类的函数屏蔽了与其同名的基类函数，规则如下：
1、如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏（注意别与重载混淆）
2、如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆）
使用了using关键字，就可以避免1的情况，是的父类同名函数在子类中得以重载，不被隐藏
*/

void testUsing1()
{
	Base b;
	Derived d;
	b.menfcn();
	d.menfcn();//如果去掉Derived类中的using声明，会出现错误：error C2660: 'Derived::menfcn' : function does not take 0 arguments    
	d.menfcn(123);
	/*
	Base function
	Base function
	Derived function with int : 123
	*/
}

//---------------------------------------test2 可以取代typedef了,而且更加灵活
using myIntVec = std::vector<int>;
void testUsing2()
{
	myIntVec mvec = { 1, 2, 3, 4, 5 };
	mvec.push_back(123);
	for (int num : mvec)
		printf("--- num:%d\n", num);

	std::cout << is_same < std::vector<int>, myIntVec>::value << std::endl; // 1
}

template <typename T>
using MapStr = std::map<T, std::string>;
void testUsing3()
{
	MapStr<int> intStrMap;
	intStrMap.insert(make_pair(123, "aaa"));
	intStrMap.insert(make_pair(456, "bbb"));

	MapStr<std::string> strstrMap;
	strstrMap.insert(make_pair("ccc", "ddd"));
	strstrMap.insert(make_pair("eee", "fff"));
}

int main()
{
	testUsing1();
	//testUsing2();
	//testUsing3();
	system("pause");
	return 0;
}
} 
