#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	//subject tests
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	//further tests
	std::cout << std::endl;
	const int animalCount = 6;
	AAnimal *tab[animalCount];

	std::string dogIdeas[] = {"Bacon, bacon, bacon!", "Squirrel!", "Did someone say walk?", "I love you human!", "Is that a tennis ball?"};
	std::string catIdeas[] = {"I'm plotting your demise.", "I deserve more treats.", "I'm not lazy, I'm energy efficient.", "I meant to do that.", "I see a red dot."};

	for (int i = 0; i < animalCount; i++) {
		if (i < animalCount / 2) {
			tab[i] = new Dog();
			for (int j = 0; j < 5; j++) static_cast<Dog*>(tab[i])->getBrain()->ideas[j] = dogIdeas[j];
		} else {
			tab[i] = new Cat();
			for (int j = 0; j < 5; j++) static_cast<Cat*>(tab[i])->getBrain()->ideas[j] = catIdeas[j];
		}
		tab[i]->makeSound();
	}

	std::cout << "----------------" << std::endl;
	for (int i = 0; i < animalCount; i++) {
		std::cout << "AAnimal " << i + 1 << " (" << tab[i]->getType() << ") thoughts: " << std::endl;
		if (tab[i]->getType() == "Dog") {
			Dog* dog = static_cast<Dog*>(tab[i]);
			for (int j = 0; j < 5; j++) std::cout << "|" << dog->getBrain()->ideas[j] << "|" << std::endl;
		} else if (tab[i]->getType() == "Cat") {
			Cat* cat = static_cast<Cat*>(tab[i]);
			for (int j = 0; j < 5; j++) std::cout << "|" << cat->getBrain()->ideas[j] << "|" << std::endl;
		}
		std::cout << "----------------" << std::endl;
	}

	for (int i = 0; i < animalCount; i++) delete tab[i];

	//deep copy tests
	std::cout << std::endl;
	Dog basic;
	basic.getBrain()->ideas[0] = "Bacon, bacon, bacon!";
	{
		Dog tmp = basic;
		std::cout << "----------------" << std::endl;
		std::cout << "| basic: " << basic.getBrain()->ideas[0] << "|" << std::endl;
		std::cout << "| tmp: " << tmp.getBrain()->ideas[0] << "|" << std::endl;
		std::cout << "----------------" << std::endl;

		tmp.getBrain()->ideas[0] = "Is that a tennis ball?";
		std::cout << "----------------" << std::endl;
		std::cout << "| basic: " << basic.getBrain()->ideas[0] << "|" << std::endl; //basic's idea should not have changed
		std::cout << "| tmp: " << tmp.getBrain()->ideas[0] << "|" << std::endl; //tmp's idea should have changed to most recent assignment
		std::cout << "----------------" << std::endl;
	}
	std::cout << "----------------" << std::endl;
	std::cout << "| basic after tmp is destroyed: " << basic.getBrain()->ideas[0] << "|" << std::endl; //will not crash if deep copy
	std::cout << "----------------" << std::endl;

	return 0;
}
