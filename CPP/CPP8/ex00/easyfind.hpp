/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:33:56 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:33:57 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

template <typename T>
int easyfind(const T &cont, int i){
	for (auto v : cont){
		if (v == i)
			return (v);
	}
	return (-1);
}
