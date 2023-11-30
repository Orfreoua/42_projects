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
	Animal();
	virtual ~Animal();
	virtual void makeSound() const;
	const std::string& getType() const;
};

#endif