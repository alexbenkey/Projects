/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:14:31 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:14:34 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("bob");
	ClapTrap james("james");
	ClapTrap tim = ClapTrap("tim");

	bob.attack(james.get_name());
	james.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.beRepaired(2);
	bob.attack(james.get_name());
	james.takeDamage(0);
	tim.attack(bob.get_name());
	bob.takeDamage(0);
	bob.beRepaired(5);
	
}