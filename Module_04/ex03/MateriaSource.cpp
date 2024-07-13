#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src){
	for (int i = 0; i < 4; i++){
		if (src.memory[i])
			this->memory[i] = src.memory[i]->clone();
		else
			this->memory[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)	{
		if (memory[i])
			delete memory[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src){
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 4; i++){
		delete memory[i];
		memory[i] = NULL;
		if (src.memory[i])
			memory[i] = src.memory[i]->clone();
		else
			memory[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (this->memory[i] == NULL){
			this->memory[i] = m;
			std::cout << "MateriaSource learned Materia " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource has no more space in memory" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++){
		if (this->memory[i] == NULL)
			continue;
		if (memory[i]->getType() == type){
			std::cout << "MateriaSource creates Materia " << type << std::endl;
			return (memory[i]->clone());
		}
	}
	std::cout << "MateriaSource can not create Materia " << type << std::endl;
	return 0;
}
