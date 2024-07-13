#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter{
private:
	std::string const name_;
	AMateria *inventory[4];
public:
	Character();
	Character(const std::string &name);
	Character(const Character &src);

	~Character();

	Character &operator=(const Character &assign);

	std::string const &getName() const;

	void equip(AMateria *m);
	void unequip(int index);
	void use(int index, ICharacter &target);
};

#endif
