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
    this->fpn_value = 0;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->fpn_value = number << this->f_bits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->fpn_value = roundf(number * (1 << this->f_bits));
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->fpn_value = rhs.fpn_value;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->fpn_value;
}

void Fixed::setRawBits(int const raw)
{
    this->fpn_value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->fpn_value / (float)(1 << this->f_bits));
}

int Fixed::toInt(void) const
{
    return (this->fpn_value >> this->f_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->fpn_value > rhs.fpn_value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->fpn_value < rhs.fpn_value);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->fpn_value >= rhs.fpn_value);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->fpn_value <= rhs.fpn_value);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->fpn_value == rhs.fpn_value);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->fpn_value != rhs.fpn_value);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++()
{
    this->fpn_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fpn_value++;
    return (temp);
}

Fixed &Fixed::operator--()
{
    this->fpn_value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fpn_value--;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.fpn_value < b.fpn_value)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.fpn_value < b.fpn_value)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.fpn_value > b.fpn_value)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.fpn_value > b.fpn_value)
        return (a);
    return (b);
}
