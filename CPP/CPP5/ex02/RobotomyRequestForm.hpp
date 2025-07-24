/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:26:37 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:26:38 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{
	public:

		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm const &rhs);
		RobotomyRequestForm &operator=(AForm const &rhs);
		~RobotomyRequestForm(void);

		void 		beSigned(Bureaucrat const &signer);
		void		execute(Bureaucrat const &signer, std::string const target) const;

	private:
		RobotomyRequestForm(void);
};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);