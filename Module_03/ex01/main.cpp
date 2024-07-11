#include "ScavTrap.hpp"

int main()
{
	ScavTrap Liam("Liam");
	ScavTrap Anon;
	std::cout << std::endl;

	Anon.guardGate();
	Liam.attack("Anonymous");
	Anon.takeDamage(0);
	Anon.attack("Liam");
	Liam.takeDamage(0);
	Anon.guardGate();

	Liam.attack("Anonymous");
	Anon.takeDamage(5);
	Anon.beRepaired(3);
	Anon.takeDamage(8);
	Anon.takeDamage(1);

	for (size_t i = 0; i < 49; i++)	{
		Liam.attack("Anonymous");
		Anon.takeDamage(20);
	}

	std::cout << std::endl;
	return 0;
}
