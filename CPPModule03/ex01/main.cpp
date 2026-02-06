#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "    CONSTRUCTION CHAIN TEST" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "[Creating ScavTrap named 'Serena']" << std::endl;
    ScavTrap serena("Serena");

    std::cout << "\n[Creating Default ScavTrap]" << std::endl;
    ScavTrap def;

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "    SCAVTRAP SPECIFIC TESTS" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    serena.attack("Target Dummy");
    
    serena.guardGate();

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "    INHERITANCE CHECKS" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    serena.takeDamage(50);
    
    serena.beRepaired(20);

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "    DESTRUCTION CHAIN TEST" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

 
    return (0);
}