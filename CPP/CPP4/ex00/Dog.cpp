/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:18:27 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:18:28 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){
	std::cout << "Dog has been constructed." << std::endl; 
}

Dog::Dog(std::string type){
	this->_type = type;
	std::cout << type << " has been constructed." << std::endl;
}

Dog::Dog(const Dog &rhs){
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs){
	this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "'Woof Woof'" << std::endl;
}

Dog::~Dog(void){
	std::cout << "Dog has been destructed" << std::endl;
}