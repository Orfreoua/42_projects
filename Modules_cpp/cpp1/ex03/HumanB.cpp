#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(NULL) {}

void HumanB::setWeapon(Weapon& humanWeapon) {
    weapon = &humanWeapon;
}

void HumanB::attack() const {
    if (weapon != NULL) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " attacks with bare hands" << std::endl;
    }
}
