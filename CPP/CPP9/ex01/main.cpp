/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:34:21 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:34:23 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "invalid input" << std::endl;
		return 0;
	}
	RPN rpn;
	rpn.convertVals(argv[1]);
	rpn.Calc();
}