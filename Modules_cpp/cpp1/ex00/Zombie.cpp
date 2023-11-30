#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) :name(name){
    //this->name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}

void Zombie::announce() const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
