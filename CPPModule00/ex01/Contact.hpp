#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact();
		~Contact();

		std::string get_fname();
		std::string get_lname();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_darkest_secret();

		void set_fname(std::string first_name);
		void set_lname(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);

};



#endif