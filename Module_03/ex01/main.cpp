#include "ScavTrap.hpp"

int main()
{
	ClapTrap Noam("ClapTrap Noam");
	ScavTrap Liam("ScavTrap Liam");
	ScavTrap Anon;
	std::cout << std::endl;

	Noam.attack("ScavTrap Anonymous");
	Anon.takeDamage(0);
	Anon.guardGate();
	Liam.attack("ScavTrap Anonymous");
	Anon.takeDamage(0);
	Anon.attack("ScavTrap Liam");
	Liam.takeDamage(0);
	Anon.guardGate();

	Liam.attack("ScavTrap Anonymous");
	Anon.takeDamage(5);
	Anon.beRepaired(3);
	Anon.takeDamage(8);
	Anon.takeDamage(1);

	for (size_t i = 0; i < 49; i++)	{
		Liam.attack("ScavTrap Anonymous");
		Anon.takeDamage(20);
	}

	std::cout << std::endl;
	return 0;
}
