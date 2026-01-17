#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

void PhoneBook::add_contact()
{
	int actualIndex = currentIndex % 8;
	contacts[actualIndex].set_fname(read_fname());
    contacts[actualIndex].set_lname(read_lname());
    contacts[actualIndex].set_nickname(read_nickname());
    contacts[actualIndex].set_phone_number(read_phone_number());
	contacts[actualIndex].set_darkest_secret(read_darkest_secret());
	currentIndex++;
}

void PhoneBook::search_contact()
{
	//burda kaldın
}

int PhoneBook::getIndex() {return currentIndex;}
void PhoneBook::setIndex(int currentIndex) {this->currentIndex = currentIndex;}