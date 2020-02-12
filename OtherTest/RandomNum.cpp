//正太分布
#include <iostream>
#include <time.h>
#include <random>
#include <functional>


namespace RandomNum
{


void randNumTest()
{
	std::minstd_rand0 generator0(time(NULL)); // linear_congruential_engine 线性同余法
	std::default_random_engine generator1(time(NULL)); // mersenne_twister_engine 梅森旋转法
	std::uniform_int_distribution<int> distInt(100, 200); // uniform_int_distribution 整数均匀分布
	std::uniform_real_distribution<float> distFloat(0.f, 100.f); // uniform_real_distribution 浮点数均匀分布

	auto dice = std::bind(distInt, generator1);
	for (int i = 0; i < 5; i++)
		std::cout << dice() << std::endl;
}

void main()
{
	randNumTest();
}

} // RandomNum
