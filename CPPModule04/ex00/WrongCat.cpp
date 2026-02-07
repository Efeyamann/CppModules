#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	type = "WrongCat";
	std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
	std::cout << "[WrongCat] copy constuctor called for " << this->type << "." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "[WrongCat] copy assignment operator called for " << this->type << "." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor called for " << this->type << "." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}