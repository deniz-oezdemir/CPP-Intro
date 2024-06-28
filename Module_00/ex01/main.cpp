#include "phonebook.hpp"

int	main(){
	PhoneBook book;
	std::cout << "Crappy Awesome Phonebook\n";
	std::cout << "Please enter ADD, SEARCH, or EXIT: ";

	std::string cmd;
	while (1){
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			book.add_contact();
		else if (cmd == "SEARCH")
			book.list_contacts();
		else if (cmd == "EXIT")
			return;
		else
			std::cout << "\nChoice invalid. Please enter ADD, SEARCH, or EXIT: ";
	}
}
