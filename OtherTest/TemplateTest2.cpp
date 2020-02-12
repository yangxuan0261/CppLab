#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

namespace TemplateTest2 {


	class Person
	{
		public:
			//template<int flag, typename T>
			template<int flag, typename T>
			int walk()
			{
				printf("--- flat:%d\n", flag);
				printf("--- sec type:%s\n", typeid(T).name());
				return 0;
			}

		public:
			std::string		mName;
			int				mAge;
	};

	void testTemplate2()
	{
		Person* pA = new Person();
		pA->mName = std::string("aaa");
		pA->mAge = 123;
		//pA->run();

		pA->template walk<123, Person>();
	}


void main()
{
	testTemplate2();
}

}
