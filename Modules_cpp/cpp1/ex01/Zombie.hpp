#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void announce();

private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif