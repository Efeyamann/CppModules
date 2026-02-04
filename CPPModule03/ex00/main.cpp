#include "ClapTrap.hpp"
int main()
{
    std::cout << "\n### TEST 1: Construction & Basic Actions ###\n" << std::endl;
    {
        ClapTrap robotA("Alpha");
        ClapTrap robotB("Beta");

        // Alpha attacks Beta (Remember: In Ex00 damage is 0 by default)
        robotA.attack("Beta");
        
        // Manual damage because attack() doesn't auto-link to the other object in this subject
        robotB.takeDamage(0); 

        // Repair test
        robotB.beRepaired(5);
    }

    std::cout << "\n### TEST 2: Energy Depletion (Loop) ###\n" << std::endl;
    {
        ClapTrap robotC("Charlie");

        // Charlie has 10 Energy. Let's force him to work 11 times.
        // The first 10 should work, the 11th should fail.
        for (int i = 1; i <= 11; i++)
        {
            std::cout << "Action " << i << ": ";
            robotC.attack("Target_Dummy");
        }
        
        // Try to repair with 0 energy
        std::cout << "Trying to repair with 0 energy: ";
        robotC.beRepaired(10);
    }

    std::cout << "\n### TEST 3: Death Logic (0 HP) ###\n" << std::endl;
    {
        ClapTrap robotD("Delta");

        // Delta takes fatal damage (10 HP initially)
        robotD.takeDamage(9);  // 1 HP left
        robotD.takeDamage(5);  // -4 HP -> Should clamp to 0

        // Try to act while dead
        std::cout << "Trying to attack while dead: ";
        robotD.attack("Enemy");
        
        std::cout << "Trying to repair while dead: ";
        robotD.beRepaired(10);
    }

    std::cout << "\n### TEST 4: Copy Constructor & Assignment Operator ###\n" << std::endl;
    {
        ClapTrap original("Original");
        original.takeDamage(5); // HP becomes 5

        // Test Copy Constructor
        ClapTrap copy(original); 
        std::cout << "Copy created. Name should be Original, HP should be 5." << std::endl;
        
        // Test Assignment Operator
        ClapTrap assigned("Assigned");
        assigned = original;
        std::cout << "Assigned created. Name should be Original, HP should be 5." << std::endl;
    } // Destructors will run here for Test 4

    std::cout << "\n### End of Tests ###\n" << std::endl;

    return 0;
}