#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

#define ARRAY_SIZE 10

class ComplexType {
	public:
		std::string	name;
		int			value;

		ComplexType() : name(""), value(0) {}
		ComplexType(std::string n, int v) : name(n), value(v) {}
};

int main(int, char**) {
	// Create an empty array
	Array<int> emptyArray;

	// Accessing elements in the empty array
	int element = 0;
	try {
		element = emptyArray[0];
		std::cout << "Accessing element[0]" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught accessing element[0]: " << e.what() << std::endl;
	}

	// Create an Array object of integers with size ARRAY_SIZE
	Array<int> values(ARRAY_SIZE);

	// Create a dynamic array of integers with size ARRAY_SIZE
	int* copies = new int[ARRAY_SIZE];

	// Seed the random number generator
	srand(time(NULL));

	// Fill the values array and copies array with random digits
	for (int i = 0; i < ARRAY_SIZE; i++) {
		int value = rand() % 10; // Generate a random digit between 0 and 9
		values[i] = value;
		copies[i] = value;
	}

	// Print the values in the values array
	std::cout << "Values array: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << values[i] << " ";
	}
	std::cout << std::endl;

	// Print the values in the copies array
	std::cout << "Copies array: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << copies[i] << " ";
	}
	std::cout << std::endl;

	// Create a temporary Array object and test Array object using copy constructor
	{
		Array<int> tmp = values;
		Array<int> test(tmp);
	}

	// Try to access an element at an index greater than or equal to ARRAY_SIZE, catch the exception and print the error message
	try {
		values[ARRAY_SIZE + 1] = 0;
	} catch(const std::exception& e) {
		std::cerr << "Exception caught accessing element out of range: " << e.what() << std::endl;
	}

	// Try to access an element at a negative index, catch the exception and print the error message
	try {
		values[-1] = 0;
	} catch(const std::exception& e) {
		std::cerr << "Exception caught accessing element at negative index: " << e.what() << std::endl;
	}

	// Fill the values array with new random digits
	for (int i = 0; i < ARRAY_SIZE; i++) {
		values[i] = rand() % 10; // Generate a random digit between 0 and 9
	}

	// Print the values in the values array
	std::cout << "Values array: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << values[i] << " ";
	}
	std::cout << std::endl;

	// Check if the values in values array and copies array are the same
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (copies[i] != values[i]) {
			std::cerr << "Different values detected" << std::endl;
			break;
		}
	}

	// Deallocate the memory for the copies array
	delete [] copies;

	// Test complex type
	Array<ComplexType> complexArray(3);
	complexArray[0] = ComplexType("First", 1);
	complexArray[1] = ComplexType("Second", 2);
	complexArray[2] = ComplexType("Third", 3);
	for (int i = 0; i < 3; ++i)
		std::cout << complexArray[i].name << ":\t" << complexArray[i].value << std::endl;

	return 0;
}
