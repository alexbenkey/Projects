/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:15:56 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:15:58 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP 
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string const name);
        ClapTrap(ClapTrap const &rhs);
        ClapTrap(std::string const name, ClapTrap const &rhs);
        ~ClapTrap(void);
        ClapTrap &          operator=(ClapTrap const &rhs);

        std::string     &get_name(void);
        void            set_name(std::string const &name);
        int             &get_hp(void);
        void            set_hp(int hp);
        int             &get_ep(void);
        void            set_ep(int ep);
        int             &get_ad(void);
        void            set_ad(int const ad);
        virtual int     get_defaulthp(void) const;
		virtual int 	get_defaultep(void) const;
		virtual int     get_defaultad(void) const;

        void attack(const std::string &target);
        virtual void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    

    private:
        const int         _defaultHP = 10;
        const int         _defaultEP = 10;
        const int         _defaultAD = 0;

    protected:

        std::string _name;
        int         _healthpoints;
        int         _energypoints;
        int         _attackdamage;

};

#endif