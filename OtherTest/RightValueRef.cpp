#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


namespace RightValueRef
{


inline int f(int _arg) { return 50 * _arg; }

void testRightValueRef()
{
	int a = 10;
	int&& b = 20;
	int&& c = 30 + a;
	int&& d = f(c);

	std::cout << "--- a value and address: " << a << ", " << &a << std::endl;
	std::cout << "--- b value and address: " << b << ", " << &b << std::endl;
	std::cout << "--- c value and address: " << c << ", " << &c << std::endl;
	std::cout << "--- d value and address: " << d << ", " << &d << std::endl;
}

void main()
{
	testRightValueRef();
}

} // RightValueRef
