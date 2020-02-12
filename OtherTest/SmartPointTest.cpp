#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>

namespace SmartPointTest {


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

void testSmartPoint1()
{
	std::unique_ptr<Human> up1(new Human);
	//std::unique_ptr<Human> h2 = h1; //编译失败，
	up1->show();

	std::unique_ptr<Human> up3 = std::move(up1); //将h1对new Human的所有权交给h3，h1置空empty
	up3->show(); //对象会随着最后拥有对象的唯一指针的生命周期的结束而结束

	//h1->show();//运行时崩溃，h1已交出对象所有权，现在为empty状态

	up3.reset();//已显式释放对象内存
	//h3->show();//运行时崩溃，已显式释放对象内存，现在为empty状态
	system("pause");
}

void testSmartPoint2()
{
	//如果std::shared_ptr<Human> sp1为empty状态，则不会进入这样的判断if(sp1)
	//void reset() _NOEXCEPT 
	//{	// release resource and convert to empty shared_ptr object
	//	shared_ptr().swap(*this);
	//}
	//use_count() {return (_Rep ? _Rep->_Use_count() : 0);}
	/*
	reset函数
	是用初始化一个shared_ptr()对象（里面的_Rep和_Ptr初始化都是nullptr），
	然后调用swap(T&a),实现将a的_Rep和_Ptr都置为nullptr
	调用过一次后，之后所以无论调多少次reset，都是做无用功

	use_count函数
	判断_Rep是否nullptr，不为nullptr则返回对象的引用次数
	*/
	std::shared_ptr<Human> sp1(new Human());
	std::shared_ptr<Human> sp2 = sp1;
	std::shared_ptr<Human> sp3 = sp1;
	printf("--- ref count:%ld\n", sp2.use_count());//3

	sp1.reset(); //显式减少引用，_Rep和_Ptr都置为nullptr，sp1为empty状态
	sp1.reset(); //做无用功
	sp1.reset(); //做无用功
	printf("--- sp1 ref count:%ld\n", sp1.use_count()); //0 
	//sp1->show(); //此时sp1为empty状态，不可以在使用sp1->show()

	printf("--- sp2 ref count:%ld\n", sp2.use_count()); //2 //因为此时sp3和sp2还保持这对对象的引用，所以对象还未被释放
	printf("--- sp3 ref count:%ld\n", sp3.use_count()); //2 

	sp2.reset();//减少引用后，_Rep和_Ptr都置为nullptr，sp2为empty状态
	printf("--- sp2 ref count:%ld\n", sp2.use_count()); //0
	printf("--- sp3 ref count:%ld\n", sp3.use_count()); //1 //因为此时sp3还保持这对对象的引用，所以对象还未被释放

	sp3.reset();//减少引用后，_Rep和_Ptr都置为nullptr，sp3为empty状态 //此时已无shared_ptr对sp3保持引用，对象被释放
	printf("--- sp3 ref count:%ld\n", sp3.use_count()); //0 
	system("pause");
}
/*
Human 构造
--- ref count:3
--- sp1 ref count:0
--- sp2 ref count:2
--- sp3 ref count:2
--- sp2 ref count:0
--- sp3 ref count:1
Human 析构
--- sp3 ref count:0
请按任意键继续. . .
*/

void testSmartPoint3()
{
	std::shared_ptr<Human> sp1(new Human());
	std::shared_ptr<Human> sp2 = sp1;
	std::weak_ptr<Human> wp = sp1; //不会影响引用计数

	printf("--- ref count:%ld\n", sp2.use_count());//2

	sp2.reset();

	printf("--- sp1 count:%ld\n", sp1.use_count());//1
	std::shared_ptr<Human> sp4 = wp.lock(); //如果此时还有对对象保持引用，这行代码结束后sp4也将会保持引用，引用计数+1
	if (sp4)
		printf("--- sp4 ref count:%ld\n", sp4.use_count());//2


	sp1.reset();
	printf("--- wp ref count:%ld\n", wp.use_count());//1
	if (sp4)
		sp4.reset(); //这行代码后，将无std::shared_ptr对对象保持引用，对象将析构
	printf("--- wp ref count:%ld\n", wp.use_count());//0

	std::shared_ptr<Human> sp5 = wp.lock(); //如果此时没有对对象保持引用，则sp5是empty状态
	if (sp5)
		printf("--- sp5 ref count:%ld\n", sp4.use_count());

}

void main()
{
	//testSmartPoint1();
	//testSmartPoint2();
	testSmartPoint3();
}

}
