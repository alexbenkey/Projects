/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:28:58 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:29:07 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm{
	public:

		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
		ShrubberyCreationForm &operator=(AForm const &rhs);
		~ShrubberyCreationForm(void);

		void 		beSigned(Bureaucrat const &signer);
		void		execute(Bureaucrat const &signer, std::string const target) const;

	private:
		ShrubberyCreationForm(void);

};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);