#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assign) {
	if (this != &assign)
		*this = assign;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
}

int ScalarConverter::checkType(const std::string& str) {
	const char* c_str_input = str.c_str();
	char* end_ptr;

	// check empty
	if (str.empty())
		return 4;
	// check char
	if (str.size() == 1 && !isdigit(c_str_input[0]))
		return 0;
	// check int
	long value = std::strtoll(c_str_input, &end_ptr, 10);
	if (*end_ptr == '\0') {
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
			return 4;
		else
			return 1;
	}
	// check float
	std::strtof(c_str_input, &end_ptr);
	if (strcmp(end_ptr, "f") == 0)
		return 2;
	// check double
	std::strtod(c_str_input, &end_ptr);
	if (*end_ptr == '\0') {
		return 3;
	}
	// impossible/nan if none of above types
	return 4;
}

void ScalarConverter::convert(const std::string& str) {
	char	char_value;
	int		int_value;
	float	float_value;
	double	double_value;
	bool	is_valid_int = true;

	// check input-type and convert
	switch (checkType(str)) {
		case 0:
			char_value = str[0];
			int_value = static_cast<int>(char_value);
			float_value = static_cast<float>(char_value);
			double_value = static_cast<double>(char_value);
			break;
		case 1:
			int_value = std::strtol(str.c_str(), NULL, 10);
			char_value = static_cast<char>(int_value);
			float_value = static_cast<float>(int_value);
			double_value = static_cast<double>(int_value);
			break;
		case 2:
			float_value = std::strtof(str.c_str(), NULL);
			char_value = static_cast<char>(float_value);
			int_value = static_cast<int>(float_value);
			double_value = static_cast<double>(float_value);
			break;
		case 3:
			double_value = std::strtod(str.c_str(), NULL);
			char_value = static_cast<char>(double_value);
			int_value = static_cast<int>(double_value);
			float_value = static_cast<float>(double_value);
			break;
		default:
			float_value = std::numeric_limits<float>::quiet_NaN();
			double_value = std::numeric_limits<double>::quiet_NaN();
			is_valid_int = false;
	}

	// print char
	if (!is_valid_int || int_value < 0 || int_value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (int_value < 32 || int_value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << char_value << "'" << std::endl;
	// print int
	if (is_valid_int && double_value >= std::numeric_limits<int>::min() && double_value <= std::numeric_limits<int>::max())
		std::cout << "int: " << int_value << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	// print float
	std::cout << "float: " << float_value << "f" << std::endl;
	// print double
	std::cout << "double: " << double_value << std::endl;
}
