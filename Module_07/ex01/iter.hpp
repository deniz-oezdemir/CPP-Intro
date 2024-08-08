#pragma once
#include <iostream>

template<typename T>
void	printFunction(T &element) {
	std::cout << element << std::endl;
}

template<typename T>
void	iter(T *array, size_t size, void (*func)(T &element)) {
	for(size_t i = 0; i < size; i++)
		func(array[i]);
}
