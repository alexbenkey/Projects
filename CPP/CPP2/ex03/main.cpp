/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:12:21 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:12:26 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main (void)
{
	Point a(0, 0);
	Point b(5, 5);
	Point c(10, 0);

	Point point_a(5, 3);
	Point point_b(5, 7);
	Point point_c(2.5, 2);
	Point point_d(2.5, 2.5);
	Point point_e(2.5, -2);
	
	bsp(a, b, c, point_a);
	bsp(a, b, c, point_b);
	bsp(a, b, c, point_c);
	bsp(a, b, c, point_d);
	bsp(a, b, c, point_e);

 }
