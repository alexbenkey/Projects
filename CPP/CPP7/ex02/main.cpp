/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:32:20 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:32:22 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"


int main(void){

	Array<unsigned int> array1(50);
	for (int i = 0; i < 50; i++){
		array1[i] = i;
	}


	Array<unsigned int> array2(500);
	for (int i (0); i < 500; i++){
		array2[i] = i * 2;
	}
	std::cout << std::endl;

	std::cout << array1.size();
	std::cout << array2.size() << std::endl;

	std::cout << "vals of array 1: " << std::endl;
	std::cout << array1 << std::endl << std::endl;
	std::cout << "vals of array 2: " << std::endl;
	std::cout << array2 << std::endl << std::endl;;
	std::cout << "array2 = array 1" << std::endl;
	array2 = array1;
	std::cout << std::endl << std::endl;;
	std::cout << "vals of array 1: " << std::endl;
	std::cout << array1 << std::endl<< std::endl;
	std::cout << "vals of array 2: " << std::endl;
	std::cout << array2 << std::endl << std::endl;

	std::cout << "trying to access specific values" << std::endl;
	int vals[5] = {45, 49, 50, 145, -1};
	for (auto i: vals){
		try{
			std::cout << "array1[: " << i << "]" << array1[i] << std::endl; }
		catch ( Array<unsigned int>::OutOfBoundsException& e ) {
			std::cout << "Error: " << e.what() << std::endl; }
	}
};