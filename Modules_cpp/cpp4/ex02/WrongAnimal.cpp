#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Generic Animal") {
 //   std::cout << "Wrong Generic Animal constructor\n";
}

WrongAnimal::~WrongAnimal() {
  //  std::cout << "Wrong Generic Animal destructor\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong Generic Animal sound\n";
}

const std::string& WrongAnimal::getType() const {
    return type;
}