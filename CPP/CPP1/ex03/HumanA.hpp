/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:47:54 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:47:55 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &Weapon);
        ~HumanA(void);

        void attack(void);
        Weapon &getWeapon(void);
        std::string getName(void);

    private:
        std::string _name;
        Weapon     &_weapon;

};

#endif