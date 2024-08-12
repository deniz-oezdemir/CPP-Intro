#include "PmergeMe.hpp"
#include <sstream>

int main(int argc, char** argv) {
	try {
		if (argc < 2)
			throw "Usage: ./PmergeMe [integer sequence]";

		std::vector<int> vector;
		std::deque<int> deque;

		for (int index = 1; index < argc; index++) {
			std::stringstream ss(argv[index]);
			int nbr;
			if (!(ss >> nbr) || !(ss.eof()))
				throw "Invalid number";
			if (nbr < 0)
				throw "Negative number";
			vector.push_back(nbr);
			deque.push_back(nbr);
		}

		double vectorSortingTime, dequeSortingTime;
		printContainers(vector, deque, 1);
		executeSortAndGetTime(vector, deque, vectorSortingTime, dequeSortingTime);

		std::cout << "Sorting in progress..." << std::endl;
		std::cout << std::endl;
		printContainers(vector, deque, 0);
		std::cout << std::endl;

		if (vectorSortingTime < dequeSortingTime) {
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector :\t";
			std::cout << "\033[32m" << std::right << std::setw(10) << vectorSortingTime << " us" << "\033[0m" << std::endl;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque :\t";
			std::cout << "\033[31m" << std::right << std::setw(10) << dequeSortingTime << " us" << "\033[0m" << std::endl;
		} else {
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector :\t";
			std::cout << "\033[31m" << std::right << std::setw(10) << vectorSortingTime << " us" << "\033[0m" << std::endl;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque :\t";
			std::cout << "\033[32m" << std::right << std::setw(10) << dequeSortingTime << " us" << "\033[0m" << std::endl;
		}
	} catch(const char *errorMsg) {
		std::cout << "Error\n" << errorMsg << std::endl;
	}
}
