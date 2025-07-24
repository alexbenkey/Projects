/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:06:48 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:06:50 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed &operator=(Fixed const &rhs);
		Fixed(Fixed const &rhs);
		~Fixed(void);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int 				_fixedPointValue;
		static const int 	_fixedPointValueBits = 8;
				
};

#endif