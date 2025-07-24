/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:47:51 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:47:52 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon):_weapon(weapon)
{
    this->_name = name;
    std::cout << "HumanA has been constructed" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA has been destructed" << std::endl;
}

Weapon &HumanA::getWeapon(void)
{
    return (this->_weapon);
}

std::string HumanA::getName(void)
{
    return (this->_name);
}

void HumanA::attack(void)
{
    std::cout << HumanA::getName() << " attacks with their weapon " << this->_weapon.getType() << std::endl;
}
