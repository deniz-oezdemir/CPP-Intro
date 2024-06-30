#include "phonebook.hpp"

int	main(){
	PhoneBook book;
	std::cout << "\n\n" << std::setw(40) << "Crappy Awesome Phonebook\n\n";
	std::cout << "\nPlease enter ADD, SEARCH, or EXIT: ";

	std::string cmd;
	while (1){
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			book.add_contact();
			std::cout << "\nPlease enter ADD, SEARCH, or EXIT: ";
		}
		else if (cmd == "SEARCH")
		{
			book.list_contacts();
			std::cout << "\nPlease enter ADD, SEARCH, or EXIT: ";
		}
		else if (cmd == "EXIT")
			return 0;
		else
			std::cout << "\nChoice invalid. Please enter ADD, SEARCH, or EXIT: ";
	}
}
