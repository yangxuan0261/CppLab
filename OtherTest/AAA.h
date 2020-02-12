#pragma once
class AAA
{
public:
	AAA();
	~AAA();

	static void test();

	void testInline(int a);
};

inline void AAA::testInline(int a)
{
	a = 123;
}