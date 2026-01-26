#include "utils.hpp"

std::string get_input(std::string prompt)
{
    std::string input = "";

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (std::cin.eof())
        {
			return ""; 
        }
        if (input.empty())
        {
            std::cout << "Field cannot be empty." << std::endl;
            continue;
        }
        return input;
    }
}

std::string format_text(std::string text)
{
	if (text.length() > 10)
		return text.substr(0, 9) + ".";
	return text;
}

bool is_digits(std::string &str)
{
	size_t i = 0;
    if (str.empty()) return false;
    while (i < str.length())
	{
        if (!std::isdigit(str[i])) 
			return false;
		i++;
    }
    return true;
}

bool is_alpha(std::string &str)
{
	size_t i = 0;
    if (str.empty()) return false;
    while (i < str.length())
	{
        if (!std::isalpha(str[i])) 
			return false;
		i++;
    }
    return true;
}