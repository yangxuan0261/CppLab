#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <type_traits>


namespace PodTest
{
    


//-------------------------- defaut 显示指定为缺省，有助于自定义无参数的构造函数的类恢复POD特制
//-------------------------------test1 平凡的（trivial）
struct Trivial1 {};

struct Trivial2 { 
public:
	int a;
private:
	int b;
};

struct Trivial3 {
	Trivial1 a;
	Trivial2 b;
};

struct Trivial4 {
	Trivial2 a[23];
};

struct Trivial5 {
	int x;
	static int y;
};

struct Trivial6 {
	Trivial6() = default; //声明了构造函数，但同时指定为default
	int w;
};

struct Trivial7 {
	Trivial7() = default; //声明了构造函数，但同时指定为default，
	Trivial7(int _w) : w(_w) {} //只要编译器默认提供的被你自定义，但default指定为默认的，
	int w;						//此时不管是否有其他构造函数，都是trivial类型
};								//但是，只能在声明是指定，在外部实现指定无效，如下面的NonTrivial2

struct NonTrivial1 { //声明了构造函数，不符合（1）
	NonTrivial1() : z(24) {}
	int z;
};

struct NonTrivial2 {
	NonTrivial2(); //声明了构造函数，即使实现中指定为default，也是 nonTrivial，不符合（1）
	int w;
};
NonTrivial2::NonTrivial2() = default;

struct NonTrivial3 {
	Trivial5 c;
	virtual void f(); //包含有虚函数，不符合(4)
};

void testTrivial()
{
	std::cout << std::is_trivial<Trivial1>::value << std::endl; // 1
	std::cout << std::is_trivial<Trivial2>::value << std::endl; // 1
	std::cout << std::is_trivial<Trivial3>::value << std::endl; // 1
	std::cout << std::is_trivial<Trivial4>::value << std::endl; // 1
	std::cout << std::is_trivial<Trivial5>::value << std::endl; // 1
	std::cout << std::is_trivial<Trivial6>::value << std::endl; // 1
	std::cout << std::is_trivial<Trivial7>::value << std::endl; // 1
	std::cout << std::is_trivial<NonTrivial1>::value << std::endl; // 0
	std::cout << std::is_trivial<NonTrivial2>::value << std::endl; // 0
	std::cout << std::is_trivial<NonTrivial3>::value << std::endl; // 0
}


//-------------------------------test2 标准布局的（standard layout）
struct B1{};
struct B2{};

struct D1 : B1 {
	B1 b;
	int i;
};

struct D2 : B1 {
	B2 b;
	int i;
};

void testStandardLayout()
{
	D1 d1;
	D2 d2;
	std::cout << (&d1) << std::endl; //0018F730 
	std::cout << (&d1.b) << std::endl; //0018F730 //与书上的不符，还是与基类共享地址
	std::cout << (&d1.i) << std::endl; //0018F734

	std::cout << std::endl;

	std::cout << (&d2) << std::endl; //0018F720
	std::cout << (&d2.b) << std::endl; //0018F720
	std::cout << (&d2.i) << std::endl; //0018F724
	std::cout << std::endl;

	std::cout << std::is_standard_layout<D1>::value << std::endl; // 0
	std::cout << std::is_standard_layout<D2>::value << std::endl; // 1
}

//-------------------------- delete 显示删除缺省函数，达到private某函数的效果
class NoCopy
{
public:
	NoCopy() = default; //由于下面声明了NoCopy(int a, int b);构造函数，所以默认构造函数会被删除，可以通过这样指定为default，否则NoCopy a;会编译错误
	NoCopy(const NoCopy& _nc) = delete;//拷贝构造显示指定为delete，所以NoCopy b(a); 会编译报错

	NoCopy(int a, int b);

	void* operator new(std::size_t) = delete;//new操作符指定为delete，所以new NoCopy();会编译报错
//private:
//	NoCopy(const NoCopy& _nc) {}
};
#include <typeinfo>

void testDeleteFunc()
{
	NoCopy a;
	//NoCopy b(a); //编译报错，被删除的函数
	//NoCopy* d = new NoCopy(); //编译报错，被删除的函数
	std::cout << std::is_trivial<NoCopy>::value << std::endl; //0，显示删除了拷贝构造就变成了非pod类
	NoCopy& b = a;
	const char* name = typeid(b).name();
	printf("------- name:%s\n", name);
}

void main()
{
	//testTrivial();
	//testStandardLayout();
	testDeleteFunc();
}
} // PodTest
