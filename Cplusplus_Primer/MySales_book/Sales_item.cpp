#include <iostream>
#include "Sales_item.h"

//std::istream& read( std::istream&, Sales_item& );

Sales_item Sales_item::add(Sales_item &other)
{
	revenue += other.revenue;
	unit_sold += other.unit_sold;
	return *this;
}

int main()
{
	Sales_item empty;
	Sales_item Primer_3rd_Ed("0-201-82470-1");
//	std::string emptyName = "empty";
//	std::string PrimerName = "Primer_3rd_Ed";

	//print
	empty.printElement("empty");
	Primer_3rd_Ed.printElement("Primer_3rd_Ed");

	read(std::cin, empty);
	empty.printElement("empty");
	return 0;
}

std::istream& read( std::istream& is, Sales_item& obj)
{
	double price;
	is >> obj.isbn >> obj.unit_sold >> price;
	if(is)
	{
		obj.revenue = obj.unit_sold * price;
	}
	else
	{
		obj = Sales_item();	//reset obj
	}
	return is;
}