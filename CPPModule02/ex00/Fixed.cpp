/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:23:06 by efe               #+#    #+#             */
/*   Updated: 2026/01/28 21:38:34 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fpn_value = 0;
}
Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called"
    *this = src;
}
Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->fpn_value = rhs.getRawBits();
    }
    return (*this);
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fpn_value;
}

void Fixed::setRawBits(int const raw)
{
    this->fpn_value = raw;
}