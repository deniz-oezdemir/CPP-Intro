#pragma once

#include <iostream>
#include <string>

class Brain{
	public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &assign);
	~Brain();

	std::string	ideas[100];
};
