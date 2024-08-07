#pragma once
#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter &operator=(const ScalarConverter& assign);
		~ScalarConverter();

		static int	checkType(const std::string& str);

	public:
		static void	convert(const std::string& str);
};
