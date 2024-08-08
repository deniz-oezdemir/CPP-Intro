#include "iter.hpp"

int main() {
	int			numbers[5] = {1, 2, 3, 4, 5};
	double		decimals[4] = {1.13, 2.13452, 3.31234, 4.12344};
	char		characters[6] = {'a', 'b', '\n', 'd', 'e', 'f'};
	std::string	names[4] = {"Noah", "Peter", "Lara", "Shelly"};

	std::cout << "Testing with integers:\n";
	iter(numbers, 5, printFunction);

	std::cout << "Testing with decimals:\n";
	iter(decimals, 4, printFunction);

	std::cout << "Testing with characters:\n";
	iter(characters, 6, printFunction);

	std::cout << "Testing with strings:\n";
	iter(names, 3, printFunction);

	return 0;
}
