#include "Dog.hpp"

Dog::Dog(): Animal()
{
	type = "Dog";
	std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
	std::cout << "[Dog] copy constuctor called for " << this->type << "." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "[Dog] copy assignment operator called for " << this->type << "." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor called for " << this->type << "." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark" << std::endl;
}