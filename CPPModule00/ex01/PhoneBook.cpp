#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook()
{
    this->currentIndex = 0;
}
PhoneBook::~PhoneBook(){}
void PhoneBook::add_contact()
{
   std::string temp_fname;
    while (true)
	{
        temp_fname = get_input("Enter First Name: ");
        if (std::cin.eof())
			return;
        if (is_alpha(temp_fname))
			break;
        std::cout << "Invalid input! First name must only contain letters." << std::endl;
    }
    std::string temp_lname;
    while (true)
	{
        temp_lname = get_input("Enter Last Name: ");
        if (std::cin.eof())
			return;
        if (is_alpha(temp_lname))
			break;
        std::cout << "Invalid input! Last name must only contain letters." << std::endl;
    }
    std::string temp_nickname = get_input("Enter Nickname: ");
    if (std::cin.eof())
		return;
    std::string temp_phone_number;
    while (true)
	{
        temp_phone_number = get_input("Enter Phone Number: ");
        if (std::cin.eof())
			return;
        if (is_digits(temp_phone_number))
			break;
        std::cout << "Invalid input! Phone number must only contain digits." << std::endl;
    }
    std::string temp_darkest_secret = get_input("Enter Darkest Secret: ");
    if (std::cin.eof())
		return;
	
	int actualIndex = currentIndex % 8;
	contacts[actualIndex].set_fname(temp_fname);
    contacts[actualIndex].set_lname(temp_lname);
    contacts[actualIndex].set_nickname(temp_nickname);
    contacts[actualIndex].set_phone_number(temp_phone_number);
	contacts[actualIndex].set_darkest_secret(temp_darkest_secret);
	std::cout << "Contact added successfully to index " << actualIndex << "." << std::endl;
	currentIndex++;
	return;
}

void PhoneBook::search_contact()
{
	int i = 0;
	int max = (currentIndex > 8) ? 8 : currentIndex;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < max)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << format_text(contacts[i].get_fname());
		std::cout << "|" << std::setw(10) << format_text(contacts[i].get_lname());
		std::cout << "|" << std::setw(10) << format_text(contacts[i].get_nickname());
		std::cout << "|" << std::endl;
		i++;
	}
	if(currentIndex != 0)
		std::cout << "---------------------------------------------" << std::endl;

	std::cout << "Please choose which conctact you want to see(0-7): ";
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof()) 
		return;
    if (input.length() == 1 && std::isdigit(input[0]))
    {
        int index = input[0] - '0';
        if (index >= 0 && index < max)
        {
            display_full_info(index);
        }
        else
        {
            std::cout << "Invalid index!" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input! Please enter a single digit." << std::endl;
    }
}

void PhoneBook::display_full_info(int index)
{
    std::cout << "First Name: " << contacts[index].get_fname() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_lname() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}

int PhoneBook::getIndex() {return currentIndex;}
void PhoneBook::setIndex(int currentIndex) {this->currentIndex = currentIndex;}