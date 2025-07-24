/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:49:23 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:49:25 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please provide an input parameter for the program" << std::endl;
		return (1);
	}
	
	Harl instance;
	std::string input = argv[1];
	for (std::string::size_type j = 0; j < input.length(); j++)
		input[j] = std::toupper(input[j]);

	instance.complain(input);
}