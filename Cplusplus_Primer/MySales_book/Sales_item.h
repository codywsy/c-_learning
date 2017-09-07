#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
#include <string>


//test for friend
// class temp{
// public:
// 	//constructor
// 	temp(): num(0){}

// 	temp haha( )
// 	{
// 		num = 1;
// 	}
// private:
// 	int num;
// };

class Sales_item{
	friend std::istream& read(std::istream&, Sales_item&);
public:
	//default constructor 
	Sales_item(const std::string &book=" "):
		isbn(book), unit_sold(0), revenue(0.0){}
	//constructor by cin	
	Sales_item(std::istream &is)
	{
		std::cout << "ISBN:" << std::endl;
		std::cin >> isbn;
		std::cout << "Unit_sold:" << std::endl;
		std::cin >> unit_sold;
		std::cout << "Revenue:" << std::endl;
		std::cin >> revenue;
	}

	double avg_price() const;
	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn==rhs.isbn;
	}

	Sales_item add(Sales_item &other);

	void printElement(const std::string &className)const
	{
		std::cout << className << std::endl;
		std::cout << "ISBN_empty:" << isbn << std::endl;
		std::cout << "units_sold:" << unit_sold << std::endl;
		std::cout << "revenue:" << revenue << std::endl;
		std::cout << std::endl;
	} 

private:
	std::string isbn;
	unsigned unit_sold;
	double revenue;
};


#endif