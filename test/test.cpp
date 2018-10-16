#include <iostream>

int main(int argc, char *argv[])
{
	int argu = 1;
	auto * const argu_quote = &argu;
	std::cout << "argu:\t" << argu << std::endl;
    std::cout << "&argu:\t" << &argu << std::endl;

	std::cout << "*argu_quote:\t" << *argu_quote << std::endl;
	std::cout << "argu_quote:\t" << argu_quote << std::endl;
	
	(*argu_quote)++;
	std::cout << "*argu_quote:\t" << *argu_quote << std::endl;
	std::cout << "argu_quote:\t" << argu_quote << std::endl;

    return 0;
}
