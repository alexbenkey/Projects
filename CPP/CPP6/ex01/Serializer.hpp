/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:29:48 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:29:51 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer {
private:
    Serializer();
    ~Serializer();
	Serializer(Serializer const &Rhs);
	Serializer& operator=(Serializer const &Rhs); 

public:
   static uintptr_t serialize(Data *ptr);
   static Data * deserialize(uintptr_t raw);

};