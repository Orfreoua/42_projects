#include "Fixed.h"
#include <cmath>

Fixed::Fixed() : rawValue(0) {}

Fixed::Fixed(const float floatValue) : rawValue(roundf(floatValue * (1 << fractionalBits))) {}

Fixed::Fixed(const int intValue) : rawValue(intValue << fractionalBits) {}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return rawValue;
}

void Fixed::setRawBits(const int raw) {
	rawValue = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(rawValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return rawValue >> fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const {
	return rawValue > other.rawValue;
}

bool Fixed::operator<(const Fixed &other) const {
	return rawValue < other.rawValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return rawValue >= other.rawValue;
}

bool Fixed::operator<=(const Fixed &other) const {
	return rawValue <= other.rawValue;
}

bool Fixed::operator==(const Fixed &other) const {
	return rawValue == other.rawValue;
}

bool Fixed::operator!=(const Fixed &other) const {
	return rawValue != other.rawValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(rawValue + other.rawValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(rawValue - other.rawValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((static_cast<long long>(rawValue) * other.rawValue) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.rawValue == 0) {
        // Gérer la division par zéro, par exemple, renvoyer une valeur spéciale ou déclencher une exception.
        // Dans cet exemple, je renvoie un objet Fixe avec une valeur spéciale.
        Fixed resultNaN;
        resultNaN.setRawBits(0xFFFFFFFF);  // Valeur spéciale pour indiquer une division par zéro.
        return resultNaN;
    }

    Fixed result;
    result.setRawBits((static_cast<long long>(rawValue) << fractionalBits) / other.rawValue);
    return result;
}

Fixed& Fixed::operator++() {
	++rawValue;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--() {
	--rawValue;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

void Fixed::print(std::ostream &out) const {
	out << toFloat();
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	fixed.print(out);
	return out;
}