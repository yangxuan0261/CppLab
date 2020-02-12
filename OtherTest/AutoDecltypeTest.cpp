#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace AutoDecltypeTest
{

//----------------------------------test1 宏实现
#define GetProperty(Var, VarName) \
    inline auto Get##VarName() const->decltype(Var) { return Var; }
#define SetProperty(Var, VarName) \
    inline void Set##VarName(decltype(Var) _v) { Var = _v; }
#define GetSetProperty(Var, VarName) \
    GetProperty(Var, VarName)        \
        SetProperty(Var, VarName)

//decltype(Var) 根据Var实际的类型推导出类型

class Pig
{
  private:
    int mAge;
    std::string mName;

  public:
    GetSetProperty(mAge, Age); //一定要在声明的变量名下面(有点习惯性的把方法写在上面，变量在下面)，不然编译报错，未定义mAge
    GetSetProperty(mName, Name);
};

void testDeclType()
{
    int iarr[10] = {0};
    decltype(iarr) ib;                        //这个时候ib的定义等价于 int ib[10];两者是一样的，不要认为ib是一个指针了，它是一个正宗的数组。
    printf("--- sizeof ib:%d\n", sizeof(ib)); //40

    Pig p;
    p.SetAge(123);
    p.SetName("uuu");

    printf("--- pig age:%d, name:%s\n", p.GetAge(), p.GetName().c_str());

    /*
	--- sizeof ib:40
	--- pig age:123, name:uuu
	*/
}

//----------------------------------test3 函数转发
double foo(int _a) { return (double)_a + 0.1; }
int foo(double _a) { return (int)_a + 1; }

template <typename T>
auto Forward(T _t) -> decltype(foo(_t))
{
    return foo(_t);
}

void testDeclType3()
{
    std::cout << Forward(2) << std::endl;   //2.1
    std::cout << Forward(0.2) << std::endl; //1
}

void main()
{
    testDeclType();
    //testDeclType3();
}

} // namespace AutoDecltypeTest
