/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:41:30 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:41:31 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int ft_strcmp(char * s1, char * s2){
	while (*s2 && *s1 && *s2 == *s1)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

std::list<int> PmergeMe::fill_list(std::vector<int> input_vec){
	std::list<int> 	list1;

	for (int i = 0; i < (int)input_vec.size(); i++){
		list1.push_back(input_vec[i]);
	}
	return (list1);
}

int main(int argc, char **argv){

	std::vector<int> 		vec1;
	std::list<int>			list1;

	if (argc < 2){
		std::cerr << "no input values" << std::endl;
		return 1;
	}
	PmergeMe p;
	for (int i = 1; i < argc; i++){
		for ( size_t j = 0; j < strlen(argv[i]); j++){
			if (!std::isdigit(j + '0')){
				std::cout << "non positive digit detected" << std::endl;
				exit (1);
			}
		}
		vec1.push_back(std::stoi(argv[i]));
	}
	std::cout << "Before: " << vec1 << std::endl;
	list1 = p.fill_list(vec1);
	clock_t vecTime = clock();
	vec1 = p.ford_johnson_vector(vec1);
	clock_t vecTime_end = clock();
	clock_t listTime = clock();
	list1 = p.ford_johnson_list(list1);
	clock_t listTime_end = clock();
	for (int i = 0; i < (int)list1.size();i++){
		std::cout << p.listGet(list1, i);
		if (i != (int)list1.size() - 1) 
            std::cout << ", "; 
	}
	std::cout << "After: " << vec1 << std::endl;
	//std::cout << "list After: " << list1 << std::endl;
	std::cout << "time to process a range of " << argc - 1 << " elements with std::vector : " << static_cast<double>(vecTime_end - vecTime) / CLOCKS_PER_SEC * 1000 << " ms "<< std::endl;
	std::cout << "time to process a range of " << argc - 1 << " elements with std::list : " << static_cast<double>(listTime_end - listTime) / CLOCKS_PER_SEC * 1000 << " ms "<< std::endl;
	std::cout << "this means that the list takes " << static_cast<double>(listTime_end - listTime) / static_cast<double>(vecTime_end - vecTime) << " times as long. " << std::endl;
	
	std::cout << std::endl;
	return (0);
}