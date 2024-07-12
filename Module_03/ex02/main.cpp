#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap Emma("ClapTrap Emma");
	ScavTrap Ava("ScavTrap Ava");

	FragTrap Liam("FragTrap Liam");
	FragTrap Anon;
	std::cout << std::endl;

	Emma.attack("ScavTrap Ava");
	Ava.takeDamage(0);
	Ava.attack("ClapTrap Emma");
	Emma.takeDamage(20);
	std::cout << std::endl;

	Liam.highFivesGuys();
	Anon.highFivesGuys();
	Liam.attack("FragTrap Anonymous");
	Anon.takeDamage(0);
	Anon.attack("FragTrap Liam");
	Liam.takeDamage(0);

	Liam.attack("FragTrap Anonymous");
	Anon.takeDamage(5);
	Anon.beRepaired(3);
	Anon.takeDamage(8);
	Anon.takeDamage(1);

	for (size_t i = 0; i < 99; i++)	{
		Liam.attack("FragTrap Anonymous");
		Anon.takeDamage(20);
	}
	Liam.highFivesGuys();

	std::cout << std::endl;
	return 0;
}
