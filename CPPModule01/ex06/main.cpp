/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:01:13 by efe               #+#    #+#             */
/*   Updated: 2026/01/28 21:04:10 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Enter only one parameter" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complainFilter(argv[1]);
    
    return 0;
}