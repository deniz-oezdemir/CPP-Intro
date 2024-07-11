#include "ClapTrap.hpp"

int main()
{
	ClapTrap Liam("Liam");
	ClapTrap Anon;
	std::cout << std::endl;

	Liam.attack("Anonymous");
	Anon.takeDamage(0);
	Anon.attack("Liam");
	Liam.takeDamage(0);

	Liam.attack("Anonymous");
	Anon.takeDamage(5);
	Anon.beRepaired(3);
	Anon.takeDamage(8);
	Anon.takeDamage(1);

	for (size_t i = 0; i < 9; i++)	{
		Liam.attack("Anonymous");
	}

	std::cout << std::endl;
	return 0;
}
