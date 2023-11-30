#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
  //  std::cout << "Cat constructor\n";
}

Cat::~Cat() {
  //  std::cout << "Cat destructor\n";
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!\n";
}
