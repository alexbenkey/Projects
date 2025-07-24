/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:20:51 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:20:52 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog: public A_Animal{
	public:
		Dog(void);
		Dog(Dog const &rhs);
		Dog(std::string const type);
		Dog &operator=(const Dog &rhs);
		~Dog(void);

		std::string getType(void) const;
		void print_brain(void) const;
		void makeSound(void) const;
		void set_idea(int i, std::string idea);

	private:
		Brain *_Brain;
};