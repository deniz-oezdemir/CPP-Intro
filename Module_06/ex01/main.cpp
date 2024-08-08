#include "Serializer.hpp"
#include <iostream>

int main() {
	Data		data;
	Data*		dataPointer;
	Data*		dataPointer2;
	uintptr_t	pointerNum;

	// Initialize data
	data.value = 42;
	data.isSorted = false;
	// Print original data
	std::cout << "Original data:" << std::endl;
	std::cout << "data.value = " << data.value << std::endl;
	std::cout << "data.isSorted = " << std::boolalpha << data.isSorted << std::endl;
	std::cout << std::endl;

	// Serialize dataPointer
	dataPointer = &data;
	std::cout << "Pointer address to Data:\t\t " << dataPointer << std::endl;
	pointerNum = Serializer::serialize(dataPointer);
	std::cout << "Address converted to uintptr_t:\t\t " << pointerNum << std::endl;
	std::cout << std::endl;

	// Deserialize pointerNum
	dataPointer2 = Serializer::deserialize(pointerNum);
	std::cout << "Converted back to pointer address:\t " << dataPointer2 << std::endl;
	std::cout << std::endl;

	// Print deserialized data
	std::cout << "Deserialized data:" << std::endl;
	std::cout << "data.value = " << dataPointer2->value << std::endl;
	std::cout << "data.isSorted = " << std::boolalpha << dataPointer2->isSorted << std::endl;
}
