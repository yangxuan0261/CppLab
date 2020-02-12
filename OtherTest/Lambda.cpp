#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>


namespace Lambda
{
    


typedef std::function<int(const std::string&)> CustomFunc;

void testFunc(CustomFunc _pFunc)
{
	std::string arg0 = "aaabbb";
	int result = _pFunc(arg0);
	printf("--- result:%d\n", result);
}

void testptrFunc()
{
	int num = 123;
	int num2 = 789;

	//按值引用
	auto func = [&](const std::string&  _str)->int 
	{
		printf("--- input str:%s\n", _str.c_str());
		num = 456;
		return 100 + num;
	};

	//外部变量按值捕获，num2按引用捕获
	auto func2 = [=, &num2](const std::string&  _str)->int
	{
		printf("--- input str:%s\n", _str.c_str());
		//num = 456; //取消注释编译报错，因为是按值捕获不能修改外部变量值
		num2 = 987; //num2是按引用捕获，所以可以修改变量值
		return 100 + num;
	};

	testFunc(func2);

	printf("--- num:%d\n", num);
	printf("--- num2:%d\n", num2);
}

void testLambda()
{
	/*
	以下是关于捕捉块的详细介绍：
	[=]通过值捕捉所有变量
	[&]通过引用捕捉所有变量
	[value]通过值捕捉value，不捕捉其它变量
	[&value]通过引用捕捉value，不捕捉其它变量
	[=, &value]默认通过值捕捉，变量value例外，通过引用捕捉
	[&, value]默认通过引用捕捉，变量value例外，通过值捕捉
	*/

	printf("--------- test1\n");
	//尾部的括号使该表达式可立即执行，}符号前就表示一个方法，加()表示执行该方法
	[]{std::cout << "Hello from Lambda!" << std::endl; }();

	printf("--------- test2\n");
	std::string result = [](const std::string& str)->std::string{return "Hello from " + str; }("second Lambda");
	std::cout << result << std::endl;

	printf("--------- test3\n");
	auto fn = [](const std::string& str)->std::string{return "Hello from " + str; };
	std::cout << fn("call 1") << std::endl;
	std::cout << fn("call 2") << std::endl;

	printf("--------- test4\n");
	std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num = 7;
	auto func = [=](int value)->bool{return value > num; };
	int counter = std::count_if(vec.begin(), vec.end(), func);
	std::cout << "Found " << counter << " values > " << num << std::endl;

	printf("--------- test5\n");
	std::vector<int> vec2 = { 11, 22, 33, 44 };
	int index = 0;
	for_each(vec2.begin(), vec2.end(), 
		[&index](int i)
	{
		printf("index:%d, value%d\n", index, i);
		index++;
	});
}

class Animal
{
public:
	Animal(int _age, std::string _name) : mAge(0), mName("")
	{
		mAge = _age;
		mName = _name;
	}

	virtual ~Animal() {}

	int Show(const std::string& _str, int _num)
	{
		printf("---- show str:%s\n", _str.c_str());
		printf("---- show num:%d\n", _num);
		return mAge;
	}

public:
	int mAge;
	std::string mName;
};

void testBind()
{
	Animal* am = new Animal(22, "uuu");
	CustomFunc func = std::bind(&Animal::Show, am, std::placeholders::_1, 123);
	std::string str = "hello2";
	int ret = func(str);
	printf("--- age:%d\n", ret);

	delete am;
	/*
	std::placeholders::_1 是调用时传进参数的占位符，CustomFunc定了几参数，就必须占多少位，严格一致
	123 是绑定时可以传进该函数的值
	*/
}

void testRefAndValCapture()
{
	int j = 12;
	auto by_val = [=]() ->int{ return j + 1; };
	auto by_ref = [&]() ->int{ return j + 1; };
	printf("--- by_val:%d\n", by_val()); //13
	printf("--- by_ref:%d\n", by_ref()); //13

	j++;
	printf("--- by_val:%d\n", by_val()); //13
	printf("--- by_ref:%d\n", by_ref()); //14
	//按值捕捉，j被视为了一个常量，一旦初始化后就不会再改变
	//按引用不做，j仍在使用父作用域中的值
}

void testModifyVal()
{
	//lambda表达式{}逻辑块内默认是const的，如果是想修改外部值的话，必须按引用捕捉，外部值会随着改变
	//如果是按值捕捉，想要修改捕捉拷贝进来的外部值，就必须指定mutable，但外部值不会改变

	int j = 12;
	printf("--- j addr:0x%x\n", &j); 
	auto by_ref = [&]()->void
	{ 
		j++; 
		printf("--- by_ref j addr:0x%x\n", &j);
	};
	by_ref();
	printf("--- by_ref:%d\n", j); //13

	//auto by_val = [=]()->void{ j++; };//编译失败
	auto by_val = [=]() mutable->void
	{ 
		j = 10; //j可以被修改了，但外部还是13
		printf("--- by_val j addr:0x%x\n", &j);
	}; 
	by_val();
	printf("--- by_val:%d\n", j); //13
	/*
	--- j addr:0x23fe10
	--- by_ref j addr:0x23fe10
	--- by_ref:13
	--- by_val j addr:0x23fdf8
	--- by_val:13
	明显按值捕捉的是拷贝出来的，地址都不一样了
	*/
}

void main()
{
	//testLambda();
	//testptrFunc();
	//testBind();
	//testRefAndValCapture();
	testModifyVal();
}

} // Lambda
