#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

#define ANIMAL_COUNT 4

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "        SUBJECT TEST: ARRAY OF ANIMALS" << std::endl;
    std::cout << "========================================" << std::endl;
    
    Animal* animals[ANIMAL_COUNT];

    for (int i = 0; i < ANIMAL_COUNT / 2; i++) {
        std::cout << "\n[Creating Dog " << i << "]" << std::endl;
        animals[i] = new Dog();
    }
    for (int i = ANIMAL_COUNT / 2; i < ANIMAL_COUNT; i++) {
        std::cout << "\n[Creating Cat " << i << "]" << std::endl;
        animals[i] = new Cat();
    }

    std::cout << "\n[Deleting ALL Animals]" << std::endl;
    for (int i = 0; i < ANIMAL_COUNT; i++) {
        std::cout << "\nDeconstruct index " << i << ":" << std::endl;
        delete animals[i];
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "        DEEP COPY TEST" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n--- 1. Testing Dog Copy Constructor ---" << std::endl;
    Dog* dog1 = new Dog();
    
    std::cout << "\n> Creating dog2 as a copy of dog1..." << std::endl;
    Dog* dog2 = new Dog(*dog1);

    std::cout << "\n> Deleting dog1..." << std::endl;
    delete dog1; 

    std::cout << "\n> Deleting dog2..." << std::endl;
    delete dog2;

    std::cout << "\n--- 2. Testing Assignment Operator ---" << std::endl;
    Dog preMsgDog;
    Dog assignedDog;
    
    std::cout << "\n> Assigning preMsgDog to assignedDog..." << std::endl;
    assignedDog = preMsgDog; 

    std::cout << "\n========================================" << std::endl;
    std::cout << "        END OF TESTS" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}
