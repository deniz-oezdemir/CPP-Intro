#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : virtual public AMateria {
public:
	Ice();
	Ice(const Ice &src);

	~Ice(void);

	Ice &operator=(const Ice &src);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
