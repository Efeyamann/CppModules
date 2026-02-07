#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] default constructor called" << "\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] copy constructor called" << "\n";
	int i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor called" << "\n";
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] assignment operator called" << "\n";
	if (this != &other)
	{
		int i = 0;
		while (i < 100)
		{
			ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
	}
	else
	{
		throw std::out_of_range("Index out of bounds in Brain::setIdea");
	}
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return ideas[index];
	}
	else
	{
		throw std::out_of_range("Index out of bounds in Brain::getIdea");
	}
}
