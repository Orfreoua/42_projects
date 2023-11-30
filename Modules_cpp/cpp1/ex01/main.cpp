#include <iostream>
#include <string>
#include "Zombie.hpp"

int main() {
    int numZombies = 5;
    std::string zombieName = "Walker";

    Zombie* horde = zombieHorde(numZombies, zombieName);

    for (int i = 0; i < numZombies; i++) {
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}