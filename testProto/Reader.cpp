#include <fstream>
#include <iostream>
#include "lm.helloworld.pb.h"

int main(void)
{
	lm::helloworld msg1;
	msg1.set_id(101);
	msg1.set_str("hello");

	// Write the new address book back to disk.
/*	std::fstream output("./log", std::ios::out | std::ios::trunc | std::ios::binary);

	if(!msg1.SerializeToOstream(&output)){
		std::cerr << "Failed to write msg." << std::endl;
		return -1;
	}
*/	return 0;
}
