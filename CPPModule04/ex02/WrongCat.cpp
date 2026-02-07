#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	type = "WrongCat";
	brain = new Brain();
	std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->type = other.type;
	this->brain = other.brain;
	std::cout << "[WrongCat] copy constuctor called for " << this->type << "." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "[WrongCat] copy assignment operator called for " << this->type << "." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
        this->brain = other.brain;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	delete brain;
	std::cout << "[WrongCat] destructor called for " << this->type << "." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
