/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:31:56 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:31:57 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>

template <typename T, typename Func>
void iter(const T *a, const size_t len, Func Function){
	for(size_t i = 0; i < len; ++i)
		Function(a[i]);
};

