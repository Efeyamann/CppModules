#include "Cat.hpp"

Cat::Cat(): Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "[Cat] default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << "[Cat] copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "[Cat] assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[Cat] destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat Cat" << std::endl;
}