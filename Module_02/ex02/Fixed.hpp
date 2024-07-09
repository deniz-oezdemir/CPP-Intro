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

	bool	operator>(Fixed const &fixed) const;
	bool	operator<(Fixed const &fixed) const;
	bool	operator>=(Fixed const &fixed) const;
	bool	operator<=(Fixed const &fixed) const;
	bool	operator==(Fixed const &fixed) const;
	bool	operator!=(Fixed const &fixed) const;

	Fixed	operator+(Fixed const &fixed);
	Fixed	operator-(Fixed const &fixed);
	Fixed	operator*(Fixed const &fixed);
	Fixed	operator/(Fixed const &fixed);

	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &floatingRepresentation, Fixed const &fixedNumber);

#endif
