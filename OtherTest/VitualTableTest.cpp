#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

namespace VitualTableTest {


	typedef std::function<void(void)> Fun0;  //适用于有实例对象

	class Base0 {
	public:
		virtual void f() { cout << "Base::f" << endl; }
		virtual void g() { cout << "Base::g" << endl; }
		virtual void h() { cout << "Base::h" << endl; }

	};

	int test0() {
		Fun0 pFun = nullptr;

		Base0 b;
		//cout << "虚函数表地址：" << (int*)(&b) << endl;
		//cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;

		// Invoke the first virtual function 
		//pFun = (Fun0)*((int*)*(int*)(&b));
		//pFun();

		system("pause");
		return 0;
	}

	typedef void(*Fun)(void);   //void类型的函数指针 //适用于无实例对象，例如全局函数等

	// ------------------------------------------------ test1 -------------------------
	class Tmp {
	public:
		short a;
		int b;
		double c;
	};

	class Base {
	public:
		Base() :base1Num(123) { cout << "Base::Base" << endl; }
		virtual ~Base() { cout << "Base::~Base" << endl; }
		virtual void f() { cout << "Base::f" << endl; }
		virtual void g() { cout << "Base::g" << endl; }
		virtual void h() { cout << "Base::h" << endl; }
		void ooo() { cout << "Base::ooo" << endl; }
		void ppp() { cout << "Base::ppp" << endl; }

	private:
		virtual void j() { cout << "Base::j" << endl; }
		int base1Num;
	};

	class Base2 {
	public:
		Base2() :base2Num(456) { cout << "Base2::Base2" << endl; }
		virtual ~Base2() { cout << "Base2::~Base2" << endl; }
		virtual void x() { cout << "Base2::x" << endl; }
		virtual void y() { cout << "Base2::y" << endl; }
		void rrr() { cout << "Base2::rrr" << endl; }
		void sss() { cout << "Base2::sss" << endl; }

	private:
		virtual void z() { cout << "Base2::z" << endl; }
		int base2Num;
	};

	class dev : public Base, public Base2 {
	public:
		virtual void f() { cout << "dev::f" << endl; }
		virtual void k() { cout << "dev::k" << endl; }
		virtual void z() { cout << "dev::z" << endl; }

	public:
		int num;
		char* str;
		dev* child;
		Tmp tmp;
		//double price; //加了个8个字节的double，字节对齐时会占用更多字节，对象大小增大
	};

	void testVirtualTable() {
		//Base b1;
		//b1.j();            //compile error

		dev d;
		d.num = 100;
		d.str = "hello world";
		//d.child = new dev;
		//d.child->num = 500;

		d.tmp.a = 31;
		d.tmp.b = 777;
		d.tmp.c = 888;
		//d.f();             //compile error

		//cout << "虚函数表地址：" << (int*)(&d) << endl;
		//cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&d) << endl;
		printf("\n");

		//通过函数指针访问到私有的j(), j()对于对象来讲本来是不可见的,指针太强大
		Fun pFun2 = nullptr;
		//第一个虚函数表指针指向
		//pFun2 = (Fun)*((int*)*(int*)(&d) + 0); //Base::~Base //析构不能调
		//pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 1); //dev::f //dev重写Base的f
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 2); //Base::g
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 3); //Base::h
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 4); //Base::j
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 5); //dev::k
		pFun2();
		//Base base1Num的存储偏移在虚函数表指针的下4个字节
		int base1Num = (int)*((int*)(&d) + 1);
		printf("--- base1Num:%d\n", base1Num); //123
		printf("\n");

		//第二个虚函数表指针指向
		//pFun2 = (Fun)*((int*)*((int*)(&d) + 1) + 0);  //Base2::~Base2 //析构不能调
		//pFun2();
		pFun2 = (Fun)*((int*)*((int*)(&d) + 2) + 1);//Base2::y
		pFun2();
		pFun2 = (Fun)*((int*)*((int*)(&d) + 2) + 2); //Base2::y
		pFun2();
		pFun2 = (Fun)*((int*)*((int*)(&d) + 2) + 3); //dev::z //dev重写Base2的z
		pFun2();
		//Base2 base2Num的存储偏移在虚函数表指针的下4个字节
		int base2Num = (int)*((int*)(&d) + 3);
		printf("--- base2Num:%d\n", base2Num); //456
		printf("\n");

		//通过地址获取成员变量
		int num = (int)*((int*)(&d) + 4);
		char* str = (char*)*((int*)(&d) + 5);
		printf("--- dev.num:%d\n", num);
		printf("--- dev.str:%s\n", str);
		printf("\n");

		//(base vtp + base1num + base2 vtp + base2num + dev::num + dev::str + dev::dev*) * 4 = 28
		//printf("--- dev size : %d\n", sizeof(dev)); //28
		//如果 dev 加多个 double 型成员，因为字节对齐是更具最大元素来对界，会得到sizeof为40，参考ByteAlign.cpp; 

		printf("--- Tmp size : %d\n", sizeof(Tmp));
		printf("--- dev size : %d\n", sizeof(dev));

		printf("--- str:0x%x\n", str);
		Tmp* tmp = (Tmp*)&(*((int*)(&d) + 7));
		printf("--- tmp:0x%x\n", tmp);
		printf("--- tmp.b:%d\n", tmp->b);

		short tmpA = (short)*((int*)(&d) + 7);
		printf("--- tmpA:%d\n", (int)tmpA);
		int tmpB = (int)*((int*)(&d) + 8);
		printf("--- tmpB:%d\n", tmpB);
		int tmpC = (int)*((int*)(&d) + 9);
		printf("--- tmpC:%d\n", tmp->c);

		//dev* child = (dev*)*((int*)(&d) + 4);
		//printf("--- child num:%d\n", child->num);

		//Base* b2 = new dev();
		////b2->k();           //compile error,父类指针无法call子类特有的虚函数

		////通过函数指针访问到子类特有的虚函数k(), 指针太强大
		//Fun pFun3 = (Fun)*((int*)*(int*)b2 + 4);
		//pFun3();
	}

	// ------------------------------------------------ test2 -------------------------
	class base_class {
	public:
		base_class() {
		}
		virtual ~base_class() {
		}

		int normal_func() {
			cout << "This is  base_class's normal_func()" << endl;
			return 0;
		}
		virtual int virtual_fuc() {
			cout << "This is  base_class's virtual_fuc()" << endl;
			return 0;
		}

	};

	class drived_class1 : public base_class {
	public:
		drived_class1() {
		}
		virtual ~drived_class1() {
		}

		int normal_func() {
			cout << "This is  drived_class1's normal_func()" << endl;
			return 0;
		}
		virtual int virtual_fuc() {
			cout << "This is  drived_class1's virtual_fuc()" << endl;
			return 0;
		}
	};

	class drived_class2 : public base_class {
	public:
		drived_class2() {
		}
		virtual ~drived_class2() {
		}

		int normal_func() {
			cout << "This is  drived_class2's normal_func()" << endl;
			return 0;
		}
		virtual int virtual_fuc() override //只有虚继承的函数才能重写
		{
			//base_class::virtual_fuc(); //调用父类方法
			cout << "This is  drived_class2's virtual_fuc()" << endl;
			return 0;
		}
	};

	int test2() {
		base_class * pbc = NULL; //父类指针
		base_class bc;
		drived_class1 dc1;
		drived_class2 dc2;

		pbc = &bc;
		pbc->normal_func();
		pbc->virtual_fuc();

		pbc = &dc1;
		pbc->normal_func(); //没有virtual关键字，父类指针会调父类的normal_func方法
		pbc->virtual_fuc(); //有virtual关键字，调子类virtual_fuc方法

		pbc = &dc2;
		pbc->normal_func();//没有virtual关键字，父类指针会调父类的normal_func方法
		pbc->virtual_fuc();//有virtual关键字，调子类virtual_fuc方法

		system("pause");
		return 0;
	}

	// ------------------------------------------------ test3 -------------------------
	class Dog {
	public:
		virtual void method1() { printf("--- Dog metho1\n"); } //第一个虚函数会生成一个虚函数表的指针，4个字节
		virtual void method2() { printf("--- Dog metho2\n"); } //以后增加的虚函数都会放在虚函数表中，不会增加大小
		void method3() {} //普通方法不会增加大小
	};

	struct Cat {
	};

	void testEmptyClass() {
		printf("--- dog size:%d\n", sizeof(Dog)); //4
		printf("--- cat size:%d\n", sizeof(Cat)); //1，空类或则结构体都会有1个字节大小，目的是在new是分配内存，可以通过地址寻找到
		printf("\n");
	}

	// ------------------------------------------------ test4 -------------------------

	struct no_virts {
		int d1;
		int d2;
	};

	class has_virts : public no_virts {
	public:
		int d3;
		virtual void foo() { printf("--- has_virts foo \n"); }
	};

	void testMemObj() {
		has_virts hv;
		hv.d1 = 111;
		hv.d2 = 222;
		hv.d3 = 333;

		//无论虚函数放在对象的哪个位置，对象中的虚函数表都是位于对象内存分布的顶端
		Fun pFunc = (Fun)*((int*)(*((int*)(&hv) + 0)) + 0); //foo方法 
		pFunc();

		int d1 = (int)*((int*)(&hv) + 1); //111
		printf("--- d1:%d\n", d1);
		int d2 = (int)*((int*)(&hv) + 2); //222
		printf("--- d2:%d\n", d2);
		int d3 = (int)*((int*)(&hv) + 3); //333
		printf("--- d3:%d\n", d3);
	}

	void main() {
		test0();
		//testVirtualTable()
		//test2();
		//testEmptyClass();
		testMemObj();
	}
}
