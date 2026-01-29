/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:23:10 by efe               #+#    #+#             */
/*   Updated: 2026/01/28 21:31:11 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fpn_value;
        static const int f_bits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &src);
		Fixed(const int number);
		Fixed(const float number);
        Fixed &operator=(const Fixed &rhs);
        ~Fixed();

		float toFloat() const;
		int toInt() const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif