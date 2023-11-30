#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
	int rawValue;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const float floatValue);
	Fixed(const int intValue);
	~Fixed();

	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;

	// Overloaded comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Overloaded arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Overloaded increment and decrement operators
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	// Static member functions
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

	void print(std::ostream &out) const;
};

// Output stream operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
