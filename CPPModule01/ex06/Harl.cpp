/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:34:07 by efe               #+#    #+#             */
/*   Updated: 2026/01/28 21:06:00 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complainFilter(std::string level)
{
    std::string levels[] = 
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    int i = 0;
    while(i < 4)
    {
        if(levels[i] == level)
        {
            break;
        }
        i++;
    }
    switch (i)
    {
    case 0:
        this->debug();
    case 1:
        this->info();
    case 2:
        this->warning();
    case 3:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}