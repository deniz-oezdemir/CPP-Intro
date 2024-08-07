#pragma once
#include "Data.h"
#include <iostream>
#include <stdint.h>

class Serializer {
	private:
		Serializer();
		Serializer(Serializer& src);
		Serializer &operator=(Serializer& assign);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
