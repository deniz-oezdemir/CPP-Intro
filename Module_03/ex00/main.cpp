#include "ClapTrap.hpp"

int main()
{
	ClapTrap Liam("ClapTrap Liam");
	ClapTrap Anon;
	std::cout << std::endl;

	Liam.attack("ClapTrap Anonymous");
	Anon.takeDamage(0);
	Anon.attack("ClapTrap Liam");
	Liam.takeDamage(0);

	Liam.attack("ClapTrap Anonymous");
	Anon.takeDamage(5);
	Anon.beRepaired(3);
	Anon.takeDamage(8);
	Anon.takeDamage(1);

	for (size_t i = 0; i < 9; i++)	{
		Liam.attack("ClapTrap Anonymous");
	}

	std::cout << std::endl;
	return 0;
}
