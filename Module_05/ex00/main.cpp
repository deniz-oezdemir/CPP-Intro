#include "Bureaucrat.hpp"

int main() {
	// Constructor exceptions
	try	{
		Bureaucrat first("Peter", 200);
	}
	catch (const std::exception& e) {
		std::cerr << std::endl << e.what() << '\n';
	}
	std::cout << std::endl;

	try	{
		Bureaucrat first("Herbert", 0);
	}
	catch (const std::exception& e) {
		std::cerr << std::endl << e.what() << '\n';
	}
	std::cout << std::endl;

	// Decrement exception
	Bureaucrat	second("Walter", 140);
	std::cout << second << std::endl; // << operator overload
	try	{
		while (1) {
			std::cout << second.getGrade() << std::endl;
			second.decrementGrade();
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	// Increment exception
	Bureaucrat	third("Dieter", 10);
	std::cout << third << std::endl;
	try	{
		while (1) {
			std::cout << third.getGrade() << std::endl;
			third.incrementGrade();
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	return (0);
}
