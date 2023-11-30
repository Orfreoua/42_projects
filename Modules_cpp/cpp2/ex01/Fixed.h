#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();

    float toFloat() const;
    int toInt() const;

    Fixed &operator=(const Fixed &other);

    void print(std::ostream &out) const;

private:
    int fixedPointValue;
    static const int fractionalBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
