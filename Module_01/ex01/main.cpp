#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(){
	size_t	size = 12;
	Zombie	*horde;

	horde = zombieHorde(size, "Zombie");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}
