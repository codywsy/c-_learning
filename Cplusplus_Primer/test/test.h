#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

class Foo{
public:
	Foo(){}
	Foo(int val): value(val){}
	int get()
	{
		return value;
	}

private:
	int value;
};

class Bar{
public:
	Bar(){}

	Foo FooVal()
	{
		callsFooVal++;
		return fval; 
	}
	void printElement()
	{
		std::cout << ival << std::endl; 
		std::cout << fval.get() << std::endl;
		std::cout << callsFooVal << std::endl;
		std::cout << num << std::endl;
	}
	

private:
	static int ival;
	static Foo fval;
	static int callsFooVal;
	static const int num = 10;
};

#endif