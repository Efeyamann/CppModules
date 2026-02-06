#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "    CONSTRUCTION CHAIN TEST" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    std::cout << "[Creating FragTrap named 'Clappy']" << std::endl;
    FragTrap clappy("Clappy");

    std::cout << "\n[Creating Default FragTrap]" << std::endl;
    FragTrap distinct;

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "    FRAGTRAP SPECIFIC TESTS" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // Test specific attributes according to subject: 
    // Hit Points (100), Energy (100), Attack (30)
    
    std::cout << "* " << "Clappy attacks a target:" << std::endl;
    clappy.attack("Bad Guy"); // Should deal 30 damage (default for FragTrap)

    std::cout << "* " << "Testing High Five request:" << std::endl;
    clappy.highFivesGuys();

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "    INHERITANCE & DAMAGE TESTS" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // Testing inherited functions
    clappy.takeDamage(20); // 100 - 20 = 80 HP
    clappy.beRepaired(10); // 80 + 10 = 90 HP, -1 Energy

    clappy.takeDamage(95); // 90 - 95 = -5 (should be 0 or dead state)
    
    // Should fail if logic handles dead state
    clappy.attack("Another Guy"); 
    clappy.highFivesGuys();

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "    DESTRUCTION CHAIN TEST" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    // Destructors called in reverse order of creation
    return (0);
}