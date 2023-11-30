#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        //horde[i] = Zombie(name);
       new (&horde[i]) Zombie(name); // grace à cette expression je peu ne rentre pas dans le destructeur.
    }
    return horde;
}
