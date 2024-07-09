#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed {
private:
	int fixedPointNumber_;
	static const int fractionalBits_ = 8;

public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed &operator=(const Fixed &copy);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int value);
	Fixed(const float value);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &floatingRepresentation, Fixed const &fixedNumber);

#endif
