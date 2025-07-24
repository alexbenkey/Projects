/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:49:04 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/23 23:49:05 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	typedef void (Harl::*memfct)(void);

	public:
		Harl			(void);
		~Harl			(void);
		void complain 	(std::string level);

	private:
		void debug		(void);
		void info 		(void);
		void warning 	(void);
		void error		(void);
};

#endif