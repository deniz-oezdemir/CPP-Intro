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
			Phonebook();
			~Phonebook();
			void	add_contact();
			void	list_contacts();
			void	select_contact();
};

#endif
