/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:41:37 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:41:43 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <string>
#include <stdio.h>
#include <string.h>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(PmergeMe & rhs);
		PmergeMe &operator=(PmergeMe & rhs);
		~PmergeMe();

		//void				sort_vec(std::vector<int> &vec);
		//bool				isSortedVec(std::vector<int> &vec);
		std::list<int> 		splitVals_list(std::list<int> &list);
		std::vector<int> 	splitVals_vec(std::vector<int> &vec);
		std::vector<int> 	&getList_list(void);

		size_t				findLowValVec(const std::vector<int>& vec, size_t start);
		void				recursiveSortVec(std::vector<int>& vec, size_t start);

		size_t				findLowValList(const std::list<int>& list, size_t start);
		void				recursiveSortList(std::list<int>& list, size_t start);

		std::list<int> 		fill_list(std::vector<int> input_vec);
		int  				listGet(std::list<int> list, int place);
		void  				listSet(std::list<int> & list, int place, int val);

		void				recursiveSortPairs_vec(std::vector<int> &vec1, std::vector<int> &vec2, size_t start);
		void 				recursiveSortPairs_list(std::list<int> &_List1, std::list<int> &list2, size_t start);
		void				sortpairs_vec(std::vector<int> &vec1, std::vector<int> &vec2);
		void				sortpairs_list(std::list<int> &list1, std::list<int> &list2);
		int 				binarySearch_vec(std::vector<int> vec, int item, int low, int high);
		int 				binarySearch_list(std::list<int> vec, int item, int low, int high);
		void 				BinaryInsertionSort_vec(std::vector<int> &to, std::vector<int> &from, int n);
		void 				BinaryInsertionSort_list(std::list<int> &to, std::list<int> &from, int n);

		std::vector<int> 	fill_jacobsthall(int max_val);
		std::vector<int>   	&ford_johnson_vector(std::vector<int> &vec1);
		std::list<int>   	&ford_johnson_list(std::list<int> &list1);

};

template <typename T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
{ 
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i) { 
        os << v[i]; 
        if (i != (int)v.size() - 1) 
            os << ", "; 
    }
    os << "]" << std::endl;
    return os; 
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& v);