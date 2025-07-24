/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:16:58 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:17:00 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap {
    public:

        DiamondTrap(std::string const name);
        ~DiamondTrap(void);
        std::string     get_name(void) const;
        int             get_defaulthp(void) const;
        int             get_defaultep(void) const;
        int             get_defaultad(void) const;
        
		void WhoAmI();

    private:

        DiamondTrap(void);
        std::string    _name;
};

#endif