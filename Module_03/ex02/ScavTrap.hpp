#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{
	private:
		bool isGuarding_;

	public:
		// Constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &src);
		// Destructor
		~ScavTrap();

		// Operator
		ScavTrap & operator=(ScavTrap &assign);

		void attack(const std::string& target);
		void guardGate();
};

#endif
