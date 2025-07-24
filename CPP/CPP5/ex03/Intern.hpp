/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:27:35 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:28:08 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class Intern{
	public:
		Intern(void);
		Intern(const Intern &rhs);
		Intern(const std::string name);
		Intern &operator=(Intern const &rhs);
		~Intern(void);

		AForm *makeForm(std::string const formName, std::string const target);

	private:
		std::string _name;
};