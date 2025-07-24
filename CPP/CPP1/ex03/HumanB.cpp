/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:47:56 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:47:58 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
    this->_name = name;
    std::cout << "HumanB has been constructed" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB has been destructed" << std::endl;
}

std::string HumanB::getName(void)
{
    return(this->_name);
}

Weapon &HumanB::getWeapon(void)
{
    return(*this->_weapon);
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack(void)
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their weapon " << this->_weapon->getType() << std::endl; 
    else
        std::cout << this->_name << " attacks with their sparkling personality" << std::endl;
}