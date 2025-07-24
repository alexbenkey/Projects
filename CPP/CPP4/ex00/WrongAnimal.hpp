/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:19:07 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:19:08 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <iostream>
#include <string>

class WrongAnimal{
	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &rhs);
		WrongAnimal(std::string type);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		virtual ~WrongAnimal(void);

		std::string getType(void) const;
		void	makeSound(void) const;

	protected:

		std::string _type;
};