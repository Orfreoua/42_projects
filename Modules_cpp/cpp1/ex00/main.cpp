#include "Zombie.hpp"

int main()
{
    Zombie z1("Mario");
    Zombie *z2;

    z2 = newZombie("Luigi");
    z1.announce();
    z2->announce();
    randomChump("Wario");
    delete z2;
    return 0;
}