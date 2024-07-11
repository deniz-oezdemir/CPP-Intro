#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Liam");
	ClapTrap b;
	std::cout << std::endl;

	a.attack("Anonymous");
	b.takeDamage(0);
	b.attack("Liam");
	a.takeDamage(0);

	a.attack("Anonymous");
	b.takeDamage(5);
	b.beRepaired(3);
	b.takeDamage(8);
	b.takeDamage(1);

	for (size_t i = 0; i < 9; i++)	{
		a.attack("Anonymous");
	}

	std::cout << std::endl;
	return 0;
}
