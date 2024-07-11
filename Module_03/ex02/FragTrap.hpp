#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap{
	public:
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &src);
		// Destructor
		~FragTrap();

		// Operator
		FragTrap & operator=(FragTrap &assign);

		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
