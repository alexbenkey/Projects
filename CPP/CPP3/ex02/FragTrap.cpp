/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:15:05 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:15:06 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{ 
    std::cout << "FragTrap was constructed" << std::endl << std::endl << std::endl;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name)
{ 
    this->set_hp(100);
    this->set_ep(100);
    this->set_ad(30);

    std::cout << "FragTrap with name: " << this->get_name() << " was created." << std::endl;
    std::cout << "it has: " 
    << get_hp() << " hp" << std::endl                        
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap with name: " << this->get_name() << " was destroyed" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "High Fives Peeps! " << std::endl;
}