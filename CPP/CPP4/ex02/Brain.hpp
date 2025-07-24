/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:20:42 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:20:43 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <iostream>
#include <string>

class Brain{
	public:

		Brain(void);
		Brain(Brain const &rhs);
		Brain &operator=(const Brain &rhs);
		virtual ~Brain(void);
		std::string get_idea(int i);
		void set_idea(int i, std::string idea);

	protected:

		std::string _ideas[100];
};