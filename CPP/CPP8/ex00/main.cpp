/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:33:58 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:34:00 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main (void){
	std::vector<int>cont[20];
	for (int i = 0; i < 20; i++)
		cont->push_back(i);
	if(easyfind(cont, 13) != -1)
		std::cout << "found" << std::endl;
	else
		std::cout << "not found" << std::endl; 
}