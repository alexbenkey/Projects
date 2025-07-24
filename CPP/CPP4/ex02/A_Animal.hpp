/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:20:37 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:20:38 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <iostream>
#include <string>
#include <memory>

class A_Animal{
	public:

		A_Animal(void);
		A_Animal(A_Animal const &rhs);
		A_Animal(std::string type);
		A_Animal &operator=(const A_Animal &rhs);
		virtual ~A_Animal(void);

		virtual std::string getType(void) const = 0;
		virtual void makeSound(void) const = 0;

	protected:
		std::string _type;
};