#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.h"

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& humanName, Weapon& humanWeapon);
    void attack() const;
};

#endif
