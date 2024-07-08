#include "Harl.hpp"

void harl_filter(char *level) {
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl harl;
	int i = 0;

	while (lvl[i] != level && i < 4)
		i++;
	switch (i) {
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;

		default:
			std::cout << ("[ Probably complaining about insignificant problems ]") << std::endl;
	}
}

int main(int ac, char **av) {
	if (ac != 2){
		std::cout << "Error: wrong arguments" << std::endl;
		return 1;
	}
	harl_filter(av[1]);
	return 0;
}
