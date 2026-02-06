#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{ 
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap Constructor called for: " << name << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this ->attack_damage = other.attack_damage;
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) 
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;

    if (this != &other) 
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void FragTrap::attack(const std::string target)
{
	if(this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "FragTrap " << name << " cannot attack because they dont have enough enery points or health!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants to high-five everyone!" << std::endl; 
}