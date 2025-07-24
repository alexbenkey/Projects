/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:27:24 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:27:34 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void):_name(""){
}

Intern::Intern(const Intern &rhs): _name(rhs._name){
}

Intern::Intern(const std::string name): _name(name){
}

Intern &Intern::operator=(Intern const &rhs){
	if(this != &rhs)
	{
		Intern *copy = this;
		return (*copy);
	}
	else
		return (*this);
}

Intern::~Intern(void){
	//std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string const formName, std::string const target){
	std::string names[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	AForm *forms[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; i++){
		if (formName == names[i]){
			std::cout << "form " << formName << " is created by intern" << std::endl;
			for (int j = 0; j < 3; j++){
				if (j != i)
					delete forms[j];
			}
			return(forms[i]);
		}
	}
	for (int j = 0; j < 3; j++)
		delete forms[j];
	std::cout << "Intern cannot create " << formName << " form" << std::endl;
	return (nullptr);
}