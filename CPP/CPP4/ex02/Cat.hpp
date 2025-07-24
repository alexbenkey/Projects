/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:20:46 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:20:48 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat: public A_Animal{
	public:
		Cat(void);
		Cat(Cat const &rhs);
		Cat(std::string type);
		Cat &operator=(const Cat &rhs);
		~Cat(void);

		void set_idea(int i, std::string idea);
		std::string getType(void) const;
		void print_brain(void) const;
		void makeSound(void) const;

	private:
		Brain *_Brain;

};