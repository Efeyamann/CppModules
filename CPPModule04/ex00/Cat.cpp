#include "Cat.hpp"

Cat::Cat(): Animal()
{
	type = "Cat";
	std::cout << "[Cat] default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
	std::cout << "[Cat] copy constuctor called for " << this->type << "." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "[Cat] copy assignment operator called for " << this->type << "." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor called for " << this->type << "." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}