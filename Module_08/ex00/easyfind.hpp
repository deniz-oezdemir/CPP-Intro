#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
void easyFind(const T& container, int number) {
	typename T::const_iterator i = std::find(container.begin(), container.end(), number);
	if (i == container.end())
		throw std::exception();
	std::cout << "Found " << *i << std::endl;
}
