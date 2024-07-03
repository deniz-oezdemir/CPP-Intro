#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(){
	Zombie	*zombie = newZombie("Olivia");
	zombie->announce();
	randomChump("Noah");
	delete zombie;
}
