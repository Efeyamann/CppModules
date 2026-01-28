/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:08:33 by efe               #+#    #+#             */
/*   Updated: 2026/01/28 18:22:00 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(std::string line, std::string s1, std::string s2)
{
    size_t pos = 0;

    if (s1.empty() || line.empty())
        return line;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    return line;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Enter 3 arguments!" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: File cannot be opened!: " << filename << std::endl;
        return 1;
    }
    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: File cannot be opened!: " << std::endl;
        inFile.close();
        return 1;
    }
    std::string line;
    while (std::getline(inFile, line))
    {
        line = replaceString(line, s1, s2);
        outFile << line;
        if (!inFile.eof())
        {
            outFile << '\n';
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}
