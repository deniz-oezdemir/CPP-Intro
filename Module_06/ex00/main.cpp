
#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: wrong arguments\nUsage: <program> <literal>" << std::endl;
		return 1;
	}
	std::cout << std::fixed; // force fixed-point notation
	std::cout << std::setprecision(1); // set one digit after decimal point
	ScalarConverter::convert(argv[1]);
}
