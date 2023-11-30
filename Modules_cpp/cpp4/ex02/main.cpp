#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Test with Animal, Dog, Cat
    const Animal* j = new Dog();  // Dog
    const Animal* i = new Cat();  // Cat

    // Display types
    std::cout << j->getType() << " " << std::endl;  // Dog
    std::cout << i->getType() << " " << std::endl;  // Cat

    // Make sounds
    i->makeSound();  // Meow! Meow!
    j->makeSound();  // Woof! Woof!

    // Clean up
    delete j;
    delete i;

    // Test with WrongAnimal and WrongCat
    const WrongAnimal* wrongI = new WrongCat();  // Wrong Cat

    // Display types
    std::cout << wrongI->getType() << " " << std::endl;  // Wrong Cat

    // Make sounds
    wrongI->makeSound();  // Wrong Cat sound

    // Clean up
    delete wrongI;

    // Test with arrays of Animal
    const int size = 6;
    Animal* animals[size] = {
        new Dog(),
        new Cat(),
        new Cat(),   // Assuming WrongCat is a type of Cat
        new Dog(),
        new Cat(),
        new Cat()    // Assuming WrongCat is a type of Cat
    };

    // Delete animals
    for (int idx = 0; idx < size; ++idx) {
        delete animals[idx];
    }

    return 0;
}
