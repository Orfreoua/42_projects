#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Test with Animal, Dog, and Cat
    const Animal* meta = new Animal();  // Generic Animal
    const Animal* j = new Dog();        // Dog
    const Animal* i = new Cat();        // Cat

    // Display types
    std::cout << j->getType() << std::endl;  // Dog
    std::cout << i->getType() << std::endl;  // Cat

    // Make sounds
    i->makeSound();  // Meow! Meow!
    j->makeSound();  // Woof! Woof!
    meta->makeSound();  // Generic Animal sound

    // Clean up
    delete meta;
    delete j;
    delete i;

    // Test with WrongAnimal and WrongCat
    const WrongAnimal* wrongMeta = new WrongAnimal();  // Wrong Generic Animal
    const WrongAnimal* wrongI = new WrongCat();        // Wrong Cat

    // Display types
    std::cout << wrongI->getType() << std::endl;  // Wrong Cat

    // Make sounds
    wrongI->makeSound();     // Wrong Cat sound
    wrongMeta->makeSound();  // Wrong Generic Animal sound

    // Clean up
    delete wrongMeta;
    delete wrongI;

    return 0;
}
