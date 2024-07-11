#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;	// 0 as a default constructed
	std::cout << ++a << std::endl;	// 1 / 2^8 as pre-increment
	std::cout << a << std::endl;	// remains at increment
	std::cout << a++ << std::endl;	// returns before post-increment is applied
	std::cout << a << std::endl;	// 2 / 2^8 as post-increment

	std::cout << b << std::endl;	// product of 5.05 and 2 with some precision loss

	std::cout << "max: " << Fixed::max( a, b ) << std::endl;

	// further tests
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	std::cout << std::endl;
	Fixed c( -42.42f );
	std::cout << "c = " << c << std::endl;
	std::cout << "b = " << b << std::endl;
	if (c > b)
		std::cout << "c > b" << std::endl;
	else
		std::cout << "c < b" << std::endl;
	if (c >= b)
		std::cout << "c >= b" << std::endl;
	if (c <= b)
		std::cout << "c <= b" << std::endl;
	if (c == b)
		std::cout << "c == b" << std::endl;
	if (c != b)
		std::cout << "c != b" << std::endl;

	std::cout << std::endl;
	std::cout << c << " + " << b << " = " << std::endl;
	std::cout << c + b << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << c << " - " << b << " = " << std::endl;
	std::cout << c - b << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << c << " * " << b << " = " << std::endl;
	std::cout << c * b << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << c << " / " << b << " = " << std::endl;
	std::cout << c / b << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << c << " / 0 = " << std::endl;
	std::cout << (c / 0) << std::endl;
	std::cout << std::endl;
	return 0;
}
