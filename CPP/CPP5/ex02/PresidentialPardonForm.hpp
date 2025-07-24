/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:26:33 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:26:34 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	public:
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm const &rhs);
		PresidentialPardonForm &operator=(AForm const &rhs);
		~PresidentialPardonForm(void);

		void 		beSigned(Bureaucrat const &signer);
		void		execute(Bureaucrat const &signer, std::string const target) const;

	private:
		PresidentialPardonForm(void);
};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);