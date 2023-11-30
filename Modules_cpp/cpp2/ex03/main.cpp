#include <iostream>
#include <cmath>
# include <sstream>
#include <unistd.h>

class Fixed {
private:
    int value;
    static const int epsilon = 100;

public:
    Fixed() : value(0) {}
    Fixed(float val) : value(roundFixed(val * epsilon)) {}

    Fixed operator-(const Fixed& other) const {
        return Fixed((value - other.value) / static_cast<float>(epsilon));
    }

    Fixed operator*(const Fixed& other) const {
        return Fixed((value * other.value) / static_cast<float>(epsilon));
    }

    bool operator>=(const Fixed& other) const {
        return value >= other.value;
    }

    bool operator<=(const Fixed& other) const {
        return value <= other.value;
    }

    bool operator==(const Fixed& other) const {
        return value == other.value;
    }

    bool operator==(float floatValue) const {
        return value == roundFixed(floatValue * epsilon);
    }

    float toFloat() const {
        return static_cast<float>(value) / epsilon;
    }

    static int roundFixed(float val) {
        return static_cast<int>(std::round(val));
    }
};

class Point {
private:
    Fixed x;
    Fixed y;

public:
    Point() : x(0), y(0) {}

    Point(float xVal, float yVal) : x(xVal), y(yVal) {}

    Point(const Point& other) : x(other.x), y(other.y) {}

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    ~Point() {}

    Fixed getX() const { return x; }

    Fixed getY() const { return y; }
};

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
    Fixed detT = (c.getX() - a.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (c.getY() - a.getY());
    Fixed det1 = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (point.getY() - a.getY());
    Fixed det2 = (c.getX() - a.getX()) * (point.getY() - a.getY()) - (point.getX() - a.getX()) * (c.getY() - a.getY());

    if (detT == Fixed(0.0f)) {
        // Le triangle est plat, ne peut pas contenir de point
        return false;
    }

    // Vérification du signe des déterminants pour déterminer la position du point par rapport au triangle
    return ((det1.toFloat() >= 0.0f && det2.toFloat() >= 0.0f && (det1.toFloat() + det2.toFloat()) <= detT.toFloat()) ||
            (det1.toFloat() <= 0.0f && det2.toFloat() <= 0.0f && (det1.toFloat() + det2.toFloat()) >= detT.toFloat()));
}

int main() {
    // Saisie des valeurs des points par l'utilisateur
    float x, y;

	while (true)
	{
		if (std::cin.eof())
	 		break ;
		std::cout << "\x1b[2J" << "\x1b[H";
		std::cout << "Entrez les coordonnées du point A (x y) : ";
		std::cin >> x >> y;
		Point a(x, y);

		std::cout << "Entrez les coordonnées du point B (x y) : ";
		std::cin >> x >> y;
		Point b(x, y);

		std::cout << "Entrez les coordonnées du point C (x y) : ";
		std::cin >> x >> y;
		Point c(x, y);

		std::cout << "Entrez les coordonnées du point à évaluer (x y) : ";
		std::cin >> x >> y;
		Point point(x, y);

		// Vérification de la position du point par rapport au triangle
		if (bsp(a, b, c, point)) {
			std::cout << "Le point (" << point.getX().toFloat() << ", " << point.getY().toFloat() << ") est à l'intérieur du triangle." << std::endl;
		} else {
			std::cout << "Le point (" << point.getX().toFloat() << ", " << point.getY().toFloat() << ") est à l'extérieur du triangle." << std::endl;
		}
		sleep(1);
	}
    return 0;
}
