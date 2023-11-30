#include "HumanA.h"
#include <iostream>

HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon) {}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
