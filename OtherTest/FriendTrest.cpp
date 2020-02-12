#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>


namespace FriendTrest
{
    

//------------------------- test1
class FT
{
public:
	FT(){}
	virtual ~FT(){}

	//FT& operator+(const FT& y)
	//{
	//	mAge += y.mAge;
	//	return *this;
	//}

	//重载+号操作符
	friend FT operator+(const FT& y1, const FT& y2)
	{
		FT newFt;
		newFt.mName = y1.mName + y2.mName;
		newFt.mAge = y1.mAge + y2.mAge + 200;
		//newFt.setData(y1.mName + y2.mName, y1.mAge + y2.mAge);
		return newFt;
	}

	//重载<<输出操作符
	friend std::ostream& operator<<(std::ostream& os, const FT& y)
	{
		os << "--- name:" << y.mName << ", age:" << y.mAge;
			return os;
	}

	void setData(std::string _name, int _age)
	{
		mName = _name;
		mAge = _age;
	}

private:
	int mAge;
	std::string mName;
};


void testFriendMethod()
{
	auto p = new FT;
	p->setData("aaa", 99);
	std::cout << *p << std::endl;;

	auto p2 = new FT;
	p2->setData("bbb", 100);
	//*p2 + *p;
	std::cout << *p2 << std::endl;;

	FT aaa = *p2 + *p;
	std::cout << aaa << std::endl;;
}

//------------------------- test2
class Poly;
typedef Poly Tom;

class AAA
{
	friend class Poly; //C++98通过，C++11通过
};

class BBB
{
	friend Poly; //C++98失败，C++11通过
};

class CCC
{
	friend Tom; //C++98失败，C++11通过
};

void testFriend2()
{
	AAA a;
	BBB b;
	CCC c;
}

void main()
{
	testFriendMethod();
	testFriend2();
}
} // FriendTrest
