/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:19:21 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:19:22 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <iostream>
#include <string>
#include <memory>

class Animal{
	public:

		Animal(void);
		Animal(Animal const &rhs);
		Animal(std::string type);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string _type;
};