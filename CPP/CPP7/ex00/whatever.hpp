/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:31:48 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:31:55 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
T const & min(const T &a, const T &b){
	return (a<=b ? a : b);
};

template <typename T>
T const & max(const T &a, const T &b){
	return (a>=b ? a : b);
};

template <typename T>
void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
};