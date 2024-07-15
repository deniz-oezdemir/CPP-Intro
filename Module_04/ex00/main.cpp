#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;

	//further tests
	const WrongAnimal* uber = new WrongCat();
	WrongCat k;
	std::cout << uber->getType() << " " << std::endl;
	uber->makeSound(); //parent class's method is called as not virtual: Wrong animal noise
	std::cout << k.getType() << " " << std::endl;
	k.makeSound(); //child class's method is called directly: Meow
	delete uber;
	return (0);
}
