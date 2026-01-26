#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

int main()
{
	PhoneBook phonebook;
	std::string input;

	while(1)
	{
		std::cout << "Please enter which operation you want to do(ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
        {
            std::cout << "Exiting Program" << std::endl;
            break;
        }
		if(input.compare("ADD") == 0)
		{
			phonebook.add_contact();
		}
		if(input.compare("SEARCH") == 0)
		{
			phonebook.search_contact();
		}
		if(input.compare("EXIT") == 0)
		{
			std::cout << "Exiting Program" << std::endl;
			break;
		}
	}
}