#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
protected:
	std::string type;
	Brain* brain;

public:
	//Animal();
	virtual ~Animal() = 0; // Déclaration de destructeur virtuel pur
	virtual void makeSound() const = 0; // Déclaration de fonction virtuelle pure
	const std::string& getType() const;
};

#endif