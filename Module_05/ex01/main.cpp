#include "Bureaucrat.hpp"
#include "Forms.hpp"

int	main() {
	// Constructor exception
	try {
		Form first("Paperwork", 50, 110);
	}
	catch(const std::exception& e) {
		std::cerr << std::endl << e.what() << '\n';
	}
	std::cout << std::endl;

	// Copy assignment
	Form	second("Contract", 100, 140);
	std::cout << second << std::endl << std::endl;
	Form	third = second;
	std::cout << third << std::endl << std::endl;

	// Signing forms
	Bureaucrat peter("Peter", 120);
	Bureaucrat herbert("Herbert", 50);
	peter.signForm(second);
	std::cout << second << std::endl;
	herbert.signForm(third);
	std::cout << third << std::endl;
	std::cout << std::endl;

	return 0;
}
