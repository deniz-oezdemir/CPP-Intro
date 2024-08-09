#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(i);

	try {
		easyFind(v, 2);
		easyFind(v, 8);
	}
	catch (std::exception &e) {
		std::cout << "Next value not found" << std::endl;
	}

	return 0;
}
