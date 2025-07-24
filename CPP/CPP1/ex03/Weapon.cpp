/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:48:08 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:48:09 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->setType(type);
    std::cout << "Weapon is consructed" << std::endl;
}    

Weapon::~Weapon(void)
{
    std::cout << "Weapon is destructed" << std::endl;
}

const std::string&   Weapon::getType(void)
{
    return(this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}