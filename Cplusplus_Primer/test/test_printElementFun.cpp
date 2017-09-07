// class Person{
// public:
// 	Person(const std::string &nm, const std::string &addr):
// 		name(nm), address(addr)
// 		{
// 		}

// 	std::string getName() const
// 	{
// 		return name;
// 	}
// 	std::string getAddress() const
// 	{
// 		return address;
// 	}

// private:
// 	std::string name;
// 	std::string address;
// }

#include <iostream>
// using namespace std;

class Screen {
public:
	typedef std::string::size_type index;
	Screen(const std::string &cont, index hei, index wid):
		contents(cont), cursor(0), height(hei), width(wid)
		{
		}
	void printElement()const
	{
		std::cout << "contents= " << contents << std::endl;
		std::cout << "cursor= " << cursor << std::endl;
		std::cout << "height= " << height << std::endl;
		std::cout << "width= " << width << std::endl;
	} 
private:
	std::string contents;
	index cursor;
	index height, width;
};

int main()
{
	Screen c1 = Screen("haha",10,10);

	c1.printElement();

	// std::cout << "contents= " << c1.contents << std::endl;
	// std::cout << "cursor= " << c1.cursor << std::endl;
	// std::cout << "height= " << c1.height << std::endl;
	// std::cout << "width= " << c1.width << std::endl;

}