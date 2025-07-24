/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:30:46 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:30:49 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include <ctime>

class Base { 
	public: 
		virtual ~Base() {} 
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void identify(Base& p);
void identify(Base* p);
Base *generate(void);