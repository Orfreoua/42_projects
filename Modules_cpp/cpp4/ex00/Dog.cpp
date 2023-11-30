#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor\n";
}

Dog::~Dog() {
    std::cout << "Dog destructor\n";
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!\n";
}
