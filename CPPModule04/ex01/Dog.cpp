#include "Dog.hpp"

Dog::Dog(): Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << "[Dog] copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "[Dog] assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "[Dog] destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}