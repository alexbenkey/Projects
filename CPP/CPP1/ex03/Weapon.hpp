/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:48:10 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:48:26 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
public:
    Weapon();
    Weapon(std::string);
    ~Weapon(void); 

    const std::string&    getType(void);
    void            setType(std::string type);

private:

    std::string _type;
};

#endif