/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:27:05 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:27:07 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm{
	public:

		AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const &rhs);
		virtual AForm &operator=(AForm const &rhs) = 0;
		virtual ~AForm(void);

		virtual	void		sign(void);
		virtual std::string get_name(void) const;
		virtual bool		get_signed(void) const;
		virtual int			get_signGrade(void) const;
		virtual int			get_execGrade(void) const;

		virtual void 		beSigned(Bureaucrat const &signer) = 0;
		virtual void		execute(Bureaucrat const &signer, std::string const target) const = 0;


		class NotSignedException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class AlreadySignedException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string	const	 _name;
		bool				_signed = false;
		int const			_signGrade;
		int const			_execGrade;

};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);
