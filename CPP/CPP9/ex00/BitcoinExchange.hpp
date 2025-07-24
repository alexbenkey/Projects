/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:34:09 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:34:12 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange { 
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange & rhs);
        BitcoinExchange & operator=(BitcoinExchange & rhs);
        ~BitcoinExchange();

        void findCurrentVal();
        void storeData(std::string data);
        float findValueFromDate(std::string date);
        bool matchDates(std::string refDate, std::string checkDate);

    private:
        std::map<std::string, float> _data;

};