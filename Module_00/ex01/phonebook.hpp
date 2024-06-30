#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook{
	private:
			Contact	contacts[8];
			int		index;
			bool	full;
	public:
			PhoneBook();
			~PhoneBook();
			void	add_contact();
			void	list_contacts();
			void	select_contact();
};

std::string	get_input(std::string detail);
std::string	truncate_str(std::string str);

#endif
