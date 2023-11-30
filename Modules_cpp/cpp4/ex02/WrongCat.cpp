#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "Wrong Cat";
    //std::cout << "Wrong Cat constructor\n";
}

WrongCat::~WrongCat() {
 //   std::cout << "Wrong Cat destructor\n";
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Cat sound\n";
}
