/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:19:49 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:20:31 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &rhs);
		WrongCat(std::string type);
		WrongCat &operator=(const WrongCat &rhs);
		~WrongCat(void);

		void	makeSound(void) const;

	private:
		std::string _type;

};