/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:19:36 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:19:37 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	public:
		Dog(void);
		Dog(Dog const &rhs);
		Dog(std::string const type);
		Dog &operator=(const Dog &rhs);
		~Dog(void);

		void print_brain(void) const;
		void makeSound(void) const;
		void set_idea(int i, std::string idea);

	private:
		Brain *_Brain;
};