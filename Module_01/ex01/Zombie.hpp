#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>

class Zombie{
private:
	std::string	name;
public:
	Zombie(std::string	name);
	Zombie();
	~Zombie();
	void	setName(std::string name);
	void	announce( void );
};

#endif
