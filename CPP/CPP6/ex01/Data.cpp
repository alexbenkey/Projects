/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:29:34 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:29:36 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {	
};

Data::Data(int value): Data(){
	this->_data = value;
};

Data::~Data(){
};

Data::Data(Data const &Rhs){
	*this = Rhs;
};

Data& Data::operator=(Data const &Rhs){
	this->_data = Rhs._data;
	return *this;
};

int Data::getData() const{
    return _data;
};