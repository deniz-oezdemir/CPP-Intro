#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter; //forward declaration

class AMateria{

protected:
	std::string type_;

public:
	AMateria();
	AMateria(const std::string &type);
	AMateria(const AMateria &src);
	virtual ~AMateria();

	AMateria &operator=(const AMateria &src);

	std::string const &getType() const;

	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target);
};

#endif
