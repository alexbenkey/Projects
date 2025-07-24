/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:48:41 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:48:43 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{ 

	if (argc != 4)
	{
		std::cout << "please provide the correct amount of arguments" << std::endl;
		return (1);
	}
	std::string 	file = argv[1];
	std::string		str1 = argv[2];
	std::string		str2 = argv[3];
	std::string		buffer;
	std::size_t		found;
	std::ifstream 	ifs(file);

	if (!ifs.is_open())
	{
		std::cout << "could not open file"  <<std::endl;
		return (1);
	}
	std::ofstream 	ofs(file + ".replace");
	while (std::getline(ifs, buffer))
	{
		while (buffer.find(str1) != std::string::npos && str1 != str2)
		{
			found = buffer.find(str1);
			buffer.erase(found, str1.length());
			buffer.insert(found, str2);
		}
		ofs << buffer << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
