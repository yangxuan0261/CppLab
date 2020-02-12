#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>



#define MakeEm2Str(E)	#E


namespace MakeEnumToString
{
    


enum MyEm
{
	ME_Apple = 0,
	ME_Banana,
	ME_Oringe,
};

void testMakeEnumToString()
{
	std::string str1 = MakeEm2Str(ME_Apple);
	std::string str2 = MakeEm2Str(ME_Banana);
	std::string str3 = MakeEm2Str(ME_Oringe);
	printf("--- str1:%s\n", str1.c_str());
	printf("--- str2:%s\n", str2.c_str());
	printf("--- str3:%s\n", str3.c_str());
}

void main()
{
	testMakeEnumToString();
}

} // MakeEnumToString
