/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:17:03 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:17:05 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:

        FragTrap(std::string const name);
        ~FragTrap(void);

        void    highFivesGuys(void);
        int     get_defaulthp(void) const;
		int     get_defaultep(void) const;
		int     get_defaultad(void) const;

    private:
        const int         _defaultHP = 100;
        const int         _defaultEP = 100;
        const int         _defaultAD = 30;

    protected:

        FragTrap(void);
};

#endif