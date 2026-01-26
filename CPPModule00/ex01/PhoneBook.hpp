#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int currentIndex;
	
	public:
		PhoneBook();
		~PhoneBook();
		
		int getIndex();
		void setIndex(int currentIndex);
		void add_contact();
		void search_contact();
		void display_full_info(int index);
};




#endif