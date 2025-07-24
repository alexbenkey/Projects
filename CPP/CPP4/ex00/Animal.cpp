/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:18:12 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:18:18 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type(""){
	std::cout << "animal has been constructed." << std::endl; 
}

Animal::Animal(std::string type): _type(type){
	std::cout << "animal with type: " << type << " has been constructed." << std::endl;
}

Animal::Animal(const Animal &rhs){
	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs){
	this->_type = rhs._type;
	return (*this);
}

Animal::~Animal(void){
	std::cout << "Animal has been destructed" << std::endl;
}

std::string Animal::getType(void) const{
	return(_type);
}

void	Animal::makeSound(void) const{
	std::cout << "'a generic animal does not make a sound'" << std::endl;
}
