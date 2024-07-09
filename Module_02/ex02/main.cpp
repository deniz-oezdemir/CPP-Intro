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

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
