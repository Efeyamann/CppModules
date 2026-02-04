#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: name(name) ,
	  hit_points(10),
	  energy_points(10),
	  attack_damage(0)
	{std::cout << "Constructor called for: " << name << std::endl;};

ClapTrap::ClapTrap()
	: hit_points(10),
	  energy_points(10),
	  attack_damage(0)
	{std::cout << "Default constructor called" << std::endl;};

ClapTrap::~ClapTrap(){};

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hit_points(other.hit_points),
	  energy_points(other.hit_points),
	  attack_damage(other.attack_damage)
	{std::cout << "Copy constructor called" << std::endl;};

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other) 
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << name << " doesnt have enough energy or health!" << std::endl;
		return;
	}

	this->hit_points += amount;
	std::cout << this->name << " repaired " << amount << " hit points!" << std::endl;
	this->energy_points--;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << name << " is already dead!" << std::endl;
		return;
	}

	if(amount >= (unsigned int)this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
	if(this->hit_points == 0)
	{
		std::cout << name << " has died!" << std::endl;
		return;
	}
	std::cout << this->name << " received " << amount << " damage!" << std::endl;
}

void ClapTrap::attack(const std::string target)
{
	if(this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << name << " cannot attack because they dont have enough enery points or health!" << std::endl;
		return;
	}
	std::cout << name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}
