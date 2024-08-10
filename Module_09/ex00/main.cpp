#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]){
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange exchange;
		exchange.openInputAndExecute(argv[1]);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
