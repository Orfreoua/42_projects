#include <iostream>
#include "Fixed.h"

/*int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}*/

int main(void)
{
	Fixed a(20);
	Fixed b(42);
	Fixed c(42);

	std::cout << "\033[1m\033[38;5;11m" << "\n -- operateur de comparaison --\n" << "\033[0m" << std::endl;

	if (a == b)
		std::cout << a << " == " << b << " TRUE" << std::endl;
	else
		std::cout << a << " == " << b << " FALSE" << std::endl;
	if (b == c)
		std::cout << b << " == " << c << " TRUE" << std::endl;
	else
		std::cout << b << " == " << c << " FALSE" << std::endl;

	if (a != b)
		std::cout << a << " != " << b << " TRUE" << std::endl;
	else
		std::cout << a << " != " << b << " FALSE" << std::endl;
	if (b != c)
		std::cout << b << " != " << c << " TRUE" << std::endl;
	else
		std::cout << b << " != " << c << " FALSE" << std::endl;

	if (a > b)
		std::cout << a << " > " << b << " TRUE" << std::endl;
	else
		std::cout << a << " > " << b << " FALSE" << std::endl;
	if (b > a)
		std::cout << b << " > " << a << " TRUE" << std::endl;
	else
		std::cout << b << " > " << a << " FALSE" << std::endl;
	if (b > c)
		std::cout << b << " > " << c << " TRUE" << std::endl;
	else
		std::cout << b << " > " << c << " FALSE" << std::endl;

	if (a < b)
		std::cout << a << " < " << b << " TRUE" << std::endl;
	else
		std::cout << a << " < " << b << " FALSE" << std::endl;
	if (b < a)
		std::cout << b << " < " << a << " TRUE" << std::endl;
	else
		std::cout << b << " < " << a << " FALSE" << std::endl;
	if (b < c)
		std::cout << b << " < " << c << " TRUE" << std::endl;
	else
		std::cout << b << " < " << c << " FALSE" << std::endl;
	
	if (a >= b)
		std::cout << a << " >= " << b << " TRUE" << std::endl;
	else
		std::cout << a << " >= " << b << " FALSE" << std::endl;
	if (b >= a)
		std::cout << b << " >= " << a << " TRUE" << std::endl;
	else
		std::cout << b << " >= " << a << " FALSE" << std::endl;
	if (b >= c)
		std::cout << b << " >= " << c << " TRUE" << std::endl;
	else
		std::cout << b << " >= " << c << " FALSE" << std::endl;
	if (a <= b)
		std::cout << a << " <= " << b << " TRUE" << std::endl;
	else
		std::cout << a << " <= " << b << " FALSE" << std::endl;
	if (b <= a)
		std::cout << b << " <= " << a << " TRUE" << std::endl;
	else
		std::cout << b << " <= " << a << " FALSE" << std::endl;
	if (b <= c)
		std::cout << b << " <= " << c << " TRUE" << std::endl;
	else
		std::cout << b << " <= " << c << " FALSE" << std::endl;
	std::cout << "\033[1m\033[38;5;11m" << "\n -- operateur d'arithmetique --\n" << "\033[0m" << std::endl;

	std::cout << a << " + " << b << " = " << (c = a + b) << std::endl;
	std::cout << a << " - " << b << " = " << (c = a - b) << std::endl;
	std::cout << a << " * " << b << " = " << (c = a * b) << std::endl;
	std::cout << b << " / " << a << " = " << (c = b / a) << std::endl;
	Fixed d(0);
	std::cout << d << " * " << b << " = " << (c = d * b) << std::endl;
	std::cout << d << " * " << d << " = " << (c = d * d) << std::endl;
	std::cout << b << " / " << d << " = " << (c = b / d) << std::endl;
	std::cout << "\033[1m\033[38;5;11m" << "\n -- operateur d'incrementation & decrementation --\n" << "\033[0m" << std::endl;
	a = 42;
	std::cout << a << "++ " << " = " << a++ << " again " << a << std::endl;
	a = 42;
	std::cout << "++" << a << " = " << ++a << " again " << a << std::endl;

	b = 24;
	std::cout << b << "-- " << " = " << b-- << " again " << b << std::endl;
	b = 24;
	std::cout << "--" << b << " = " << --b << " again " << b << std::endl;

	std::cout << "\033[1m\033[38;5;11m" << "\n -- Min & Max --\n" << "\033[0m" << std::endl;

	std::cout << a << " & " << b << " MIN  = " << Fixed::min( a, b ) << std::endl;
	std::cout << a << " & " << b << " MAX  = " << Fixed::max( a, b ) << std::endl;
	std::cout << a << " & " << a << " MIN  = " << Fixed::min( a, a ) << std::endl;
	std::cout << b << " & " << b << " MAX  = " << Fixed::max( b, b ) << std::endl;
	d = -3;
	std::cout << a << " & " << d << " MIN  = " << Fixed::min( a, d ) << std::endl;
	std::cout << b << " & " << d << " MAX  = " << Fixed::max( b, d ) << std::endl;

	std::cout << "\033[1m\033[38;5;11m" << "\n -- Tests de base du sujet --\n" << "\033[0m" << std::endl;
	Fixed g;
	Fixed const h( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << g << std::endl;
	std::cout << ++g << std::endl;
	std::cout << g << std::endl;
	std::cout << g++ << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	std::cout << Fixed::max( g, h ) << std::endl;
	return (0);
}
