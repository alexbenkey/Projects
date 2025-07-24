/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:17:06 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:17:25 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main (void)
{
    DiamondTrap bill("bill");

    bill.attack("bob");
    bill.WhoAmI();
}