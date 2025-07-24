/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:29:40 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:29:41 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data* Ptr = new Data(66);
    uintptr_t serializedPtr = Serializer::serialize(Ptr);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    if (Ptr != deserializedPtr) {
		std::cout << "something went wrong, address of Ptr: " << Ptr << ", address of deserializedPtr: " << deserializedPtr << std::endl;
    } 
	else {
        std::cout << "Success!" << std::endl;
		std::cout << "Original data: " << Ptr->getData() << std::endl;
		std::cout << "Deserialized data: " << deserializedPtr->getData() << std::endl;
	}

    delete Ptr;
    return 0;
}