/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:19:47 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:19:48 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat"){

	std::cout << "WrongCat has been constructed." << std::endl; 
}

WrongCat::WrongCat(std::string type){
	this->_type = type;
	std::cout << "WrongCat with type: " << type << " has been constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs){
	*this = rhs;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs){
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << "'oink oink'" << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat has been destructed" << std::endl;
}