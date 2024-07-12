#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &src);
		~FragTrap();

		FragTrap & operator=(FragTrap &assign);

		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
