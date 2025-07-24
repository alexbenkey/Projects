/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:17:01 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:17:02 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{ 
    _healthpoints = _defaultHP;
    _energypoints = _defaultEP;
    _attackdamage = _defaultAD;
    std::cout << "FragTrap was constructed" << std::endl << std::endl << std::endl;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name)
{ 
    _healthpoints = FragTrap::get_defaulthp();
    _energypoints = FragTrap::get_defaultep();
    _attackdamage = FragTrap::get_defaultad();

    std::cout << "FragTrap with name: " << this->get_name() << " was created." << std::endl;
    std::cout << "it has: " 
    << get_hp() << " hp" << std::endl                        
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

int   FragTrap::get_defaulthp(void) const{
    return (_defaultHP);
}

int   FragTrap::get_defaultep(void) const{
    return (_defaultEP);
}

int   FragTrap::get_defaultad(void) const{
    return (_defaultAD);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap with name: " << this->get_name() << " was destroyed" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "High Fives Peeps! " << std::endl;
}