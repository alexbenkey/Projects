/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:14:54 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:14:56 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:

        ScavTrap(std::string const name);
        ~ScavTrap(void);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void guardGate(void);

    private:

        int _gatemode;
        ScavTrap(void);
};

#endif