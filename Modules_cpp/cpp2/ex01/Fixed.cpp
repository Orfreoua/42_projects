#include "Fixed.h"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixedPointValue(value << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixedPointValue(roundf(value * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &other) : fixedPointValue(other.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
    Fixed::operator=(other);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return fixedPointValue >> fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

void Fixed::print(std::ostream &out) const {
    out << toFloat();
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    fixed.print(out);
    return out;
}
