#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>


namespace MutipleArgsTest
{


//---------------------------- test1 for function
enum  LuaParameterType
{
	LPT_NUM = 0,
	LPT_STR,
	LPT_BOOL,
	LPT_CUSTOM,
	LPT_COUNT,
};
struct  LuaParameter
{
	LuaParameterType type;     //类型
	void* value;		       //自定义类型值
	double num;                //number
	bool b;                //bool
	std::string str;          //字符串类型
	std::string typeName;      //在类型为自定义类型时有效
	std::string name;          //预设时用到这个数据
};


std::vector<LuaParameter> mutipleArgsVec;
void insertArg(bool _b)
{
	LuaParameter para;
	para.type = LPT_BOOL;
	para.b = _b;
	mutipleArgsVec.push_back(para);
}
void insertArg(char _c)
{
	LuaParameter para;
	para.type = LPT_STR;
	char tmp[2] = { _c, '\0' };
	para.str = std::string(tmp);
	mutipleArgsVec.push_back(para);
}
void insertArg(const char* _str)
{
	LuaParameter para;
	para.type = LPT_STR;
	para.str = std::string(_str);
	mutipleArgsVec.push_back(para);
}
void insertArg(std::string _str)
{
	LuaParameter para;
	para.type = LPT_STR;
	para.str = std::string(_str);
	mutipleArgsVec.push_back(para);
}
void insertArg(int _num)
{
	LuaParameter para;
	para.type = LPT_NUM;
	para.num = _num;
	mutipleArgsVec.push_back(para);
}
void insertArg(float _num)
{
	LuaParameter para;
	para.type = LPT_NUM;
	para.num = _num;
	mutipleArgsVec.push_back(para);
}

void printData()
{
	for (LuaParameter para : mutipleArgsVec)
	{
		if (para.type == LPT_NUM)
		{
			printf("--- is number:%lf\n", para.num);
		}
		else if (para.type == LPT_STR)
		{
			printf("--- is string:%s\n", para.str.c_str());
		}
		else if (para.type == LPT_BOOL)
		{
			printf("--- is bool:%d\n", (int)para.b);
		}
	}
}

//--------------------- 实现模板的递归 begin ------------------
template <typename... Args>
void showArgs(Args... _args); //变长模板声明，一定要最上面，不然编译报错

//definition for 0 parameters -- 无参数时，最后一次递归时会调用，停止递归，实现为空即可
void showArgs() {} //边界条件

//definition for 1 or more parameters -- 有参数是调用这个函数
template < typename T, typename... Args> //偏特化递归定义
void showArgs(T value, Args... _args)
{
	insertArg(value);
	showArgs(_args...);
}
//--------------------- 实现模板的递归 end ------------------

void testArgsForFunc()
{
	mutipleArgsVec.clear();
	showArgs(123, "aaa", 23.23f, 'c', true);
	printData();
}

//---------------------------- test2 for class
//--------------------- 实现模板的递归 begin ------------------
template < typename... Args>
class MultiArgs; //变长模板声明，一定要最上面，不然编译报错

template <>
class MultiArgs<> {}; //边界条件，终止继承递归

template < typename T, typename... Args>
class MultiArgs<T, Args...> : public MultiArgs<Args...> //偏特化递归定义
{
public:
	MultiArgs(T _t, Args... _args) : MultiArgs<Args...>(_args...)
	{ 
		value = _t;
		std::cout << "--- addr:0x" << this << ", value:" << _t << std::endl;
		//TODO:这里可以实现处理参数_t的逻辑，
		//比如丢重载各种匹配参数的函数，到自定义数据结构的容器中
	}
public:
	T value;
};
//--------------------- 实现模板的递归 begin ------------------

template <typename... Args>
void sendMsg(Args... _args)
{
	//计算变长报的长度：sizeof...(Args)
	int argsLength = sizeof...(Args);
	std::cout << "--- _args length:" << argsLength << std::endl; //多参数使用时一定要带上...
	MultiArgs<Args...> ma(_args...);
}

void testArgsForClass()
{
	sendMsg(111, "yang", 22.22f, true);
}
/*
结果：
--- _args length:4
--- addr:0x0016F72C, value:1
--- addr:0x0016F72C, value:22.22
--- addr:0x0016F72C, value:yang
--- addr:0x0016F72C, value:111
类的初始化顺序是先初始化构造函数：后面的东西，再初始化{}块里的东西，
所以打印的顺序是传入sendMsg参数时的顺序反过来
*/

//---------------------------- test3 std::tuple在头文件<tuple>中
using MyPairRet = std::pair<int, std::string>;
using MyTupleRet = std::tuple<int, std::string, float, char>; //自定义多类型的pair-tuple

//----- print begin
template <typename Tuple, std::size_t N>
struct TuplePrinter {
	static void print(const Tuple& t)
	{
		TuplePrinter<Tuple, N - 1>::print(t);
		std::cout << ", " << std::get<N - 1>(t);
	}
};

template <typename Tuple>
struct TuplePrinter<Tuple, 1>{
	static void print(const Tuple& t)
	{
		std::cout << std::get<0>(t);
	}
};

template <typename... Args>
void PrintTuple(const std::tuple<Args...>& t)
{
	std::cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	std::cout << ")\n";
}
//----- print end

MyPairRet GetPairRet()
{
	return MyPairRet(111, "aaa");
}

MyTupleRet GetTupleRet()
{
	return MyTupleRet(222, "bbb", 333.33f, 'w');
}

void testTuple()
{
	MyPairRet pairRet = GetPairRet();
	printf("--- pair first:%d, second:%s\n", pairRet.first, pairRet.second.c_str());

	MyTupleRet tupleRet = GetTupleRet();
	//std::tuple_element<0, MyTupleRet>::type e1 = std::get<0>(tupleRet); //没有auto用的方便
	//auto e1 = std::get<0>(tupleRet);
	//auto e2 = std::get<1>(tupleRet);
	//auto e3 = std::get<2>(tupleRet);
	//auto e4 = std::get<3>(tupleRet);
	//printf("--- e1:%d, e2:%s, e3:%f, e4:%c\n", e1, e2.c_str(), e3, e4); //比较挫的输出

	PrintTuple(tupleRet); //比较聪明输出
}


void main()
{
	//testArgsForFunc();
	testArgsForClass();
	//testTuple();
}
} // MutipleArgsTest
