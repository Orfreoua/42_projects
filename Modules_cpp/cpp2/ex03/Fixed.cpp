#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(float val) : value(roundFixed(val * epsilon)) {}

bool Fixed::operator>(const Fixed& other) const {
    return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
    return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(static_cast<float>(value + other.value) / epsilon);
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(static_cast<float>(value - other.value) / epsilon);
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(static_cast<float>(value * other.value) / (epsilon * epsilon));
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.value != 0) {
        return Fixed(static_cast<float>(value) / other.value);
    } else {
        // Gestion de la division par zéro
        std::cerr << "Error: Division by zero!" << std::endl;
        return Fixed();
    }
}

Fixed& Fixed::operator++() {
    ++value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed Fixed::findMin(const Fixed& a, const Fixed& b) {
    return (a.value < b.value) ? a : b;
}

Fixed Fixed::findMax(const Fixed& a, const Fixed& b) {
    return (a.value > b.value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.value < b.value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.value > b.value) ? a : b;
}

float Fixed::toFloat() const {
    return static_cast<float>(value) / epsilon;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

int Fixed::roundFixed(float val) {
    return static_cast<int>(std::round(val));
}