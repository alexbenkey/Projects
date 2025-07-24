/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:18:21 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:18:23 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"){

	std::cout << "Cat has been constructed." << std::endl; 
}

Cat::Cat(std::string type){
	this->_type = type;
	std::cout << type << " has been constructed." << std::endl;
}

Cat::Cat(const Cat &rhs){
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs){
	this->_type = rhs._type;
	return (*this);
}

Cat::~Cat(void){
	std::cout << "Cat has been destructed" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "'Miaaaauw'" << std::endl;
}

