#include <iostream>
#include "Sales_item.h"

using namespace std; 

// int main()
// {
// 	Sales_item book; // read ISBN, number of copies sold, and sales price
// 	std::cin >> book;	//write ISBN, numberof cpies sold, total revenue, and price
// 	std::cout << book << std::endl;
// 	return 0;
// }

// int main()
// {
// 	Sales_item item1, item2;
// 	std::cin >> item1 >> item2;
// 	std::cout << item1+item2 << std::endl;
// 	return 0;
// }

int main()
{
	Sales_item total, trans;

	//读入交易
	std::cout << "Enter transactins:" << std::endl;

	if(std::cin >> total)
	{
		while(std::cin >> trans)
			if(total.same_isbn(trans))	//ISBN相同
				total = total + trans;
			else
			{
				std::cout << "Different ISBN." << std::endl;
				return -1;
			}

		//输出交易之和
		std::cout << "The total information: " << std::endl
				 << "ISBN, number if copies sold, "
				 << "total revenue, and avergae price are:"
				 << std::endl << total;
			
	}
    else
    {
    	std::cout << "No data?!" << std::endl;
    	return -1;
    }

    return 0;

}