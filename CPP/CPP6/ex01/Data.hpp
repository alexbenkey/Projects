/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:29:37 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:29:39 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Data {
private:
    int _data;
	Data();

public:

    Data(int value);
	~Data();
	Data(Data const &Rhs);
	Data& operator=(Data const &Rhs);

    int getData() const;
};
