#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.h"

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(const std::string& humanName);
    void setWeapon(Weapon& humanWeapon);
    void attack() const;
};

#endif
