#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
}

void Zombie::announce() {
    std::cout << this->name << " Braiiiiiiinnnssss..." << std::endl;
}