/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:34:29 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:34:44 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>

class RPN {
	public:
		RPN();
    	RPN(RPN & rhs);
    	RPN & operator=(RPN & rhs);
    	~RPN();

		void printResult(void);
		void convertVals(std::string input);
		void Calc();
		int		calcInd(int val1, int val2, char val3);
		int add(int val1, int val2);
		int sub(int val1, int val2);
		int mult(int val1, int val2);
		int div(int val1, int val2);

	private:

		int					_result;
		std::deque<char> 	_formula;

};