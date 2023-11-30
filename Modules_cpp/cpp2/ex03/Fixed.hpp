#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    // Constructeurs
    Fixed();
    Fixed(float val);

    // Opérateurs de comparaison
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Opérateurs arithmétiques
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Opérateurs d'incrémentation/décrémentation
    Fixed& operator++();    // Pré-incrémentation
    Fixed operator++(int);  // Post-incrémentation
    Fixed& operator--();    // Pré-décrémentation
    Fixed operator--(int);  // Post-décrémentation

    // Fonctions membres statiques pour trouver le minimum et le maximum
    static Fixed findMin(const Fixed& a, const Fixed& b);
    static Fixed findMax(const Fixed& a, const Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // Fonction pour obtenir la valeur à virgule flottante
    float toFloat() const;

    // Fonction d'affichage
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

private:
    int value;  // La représentation interne de votre nombre à virgule fixe

    static const int frac_bits = 8;  // Nombre de bits après la virgule
    static const int epsilon = 1 << frac_bits;  // Valeur de l'unité epsilon

    // Fonction d'arrondi
    static int roundFixed(float val);
};

#endif // FIXED_HPP
