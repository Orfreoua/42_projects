#include "Animal.hpp"

/*Animal::Animal() : type("Generic Animal"), brain(new Brain()) {
  //  std::cout << "Generic Animal constructor\n";
}*/

Animal::~Animal() {
    std::cout << "Abstract Animal destructor\n";
}

/*void Animal::makeSound() const {
    std::cout << "Generic Animal sound\n";
}*/

const std::string& Animal::getType() const {
    return type;
}
