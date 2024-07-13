#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("nothing");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	//further tests
	std::cout << std::endl;
	me->use(2, *bob); //nothing
	me->use(3, *bob); //nothing
	me->use(4, *bob); //slot out of range

	// deep copy test
	std::cout << std::endl;
	Character original("original");
	tmp = src->createMateria("ice");
	original.equip(tmp);
	Character copy = original;
	original.use(0, *bob);
	copy.use(0, *bob);
	original.unequip(0);
	delete(tmp);
	original.use(0, *bob); //should not have anything at the slot anymore
	copy.use(0, *bob); //should still have ice at the slot if deep copy

	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}
