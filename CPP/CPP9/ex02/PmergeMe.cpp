/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:41:34 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:41:35 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
	
PmergeMe::PmergeMe(PmergeMe & rhs){
	*this = rhs;
};

PmergeMe & PmergeMe::operator=(PmergeMe & rhs){
	if (this != &rhs)
		return (*this);
	return rhs;
};

size_t PmergeMe::findLowValList(const std::list<int>& list, size_t start) {
    size_t  lowValIndex = start;
    for (size_t  i = start + 1; i < list.size(); i++) {
        if (listGet(list, i) < listGet(list, lowValIndex)) {
            lowValIndex = i;
        }
    }
    return lowValIndex;
}

void  PmergeMe::listSet(std::list<int> & list, int place, int val){
    std::list<int>::iterator it = list.begin();
    for(int i=0; i < place; i++){
        ++it;
    }
    *it = val;
}

int  PmergeMe::listGet(std::list<int> list, int place){
    std::list<int>::iterator it = list.begin();
    for(int i=0; i < place; i++){
        ++it;
    }
    return *it;
}

void PmergeMe::recursiveSortList(std::list<int>& list, size_t start) {
    int temp1;
    int temp2;
    if ((size_t)start >= list.size() - 1) {
        return;
    }
    size_t  minIndex = findLowValList(list, start);
    if (minIndex != start) {
        temp1 = listGet(list, start);
        temp2 = listGet(list, minIndex);
        listSet(list, start, temp2);
        listSet(list, minIndex, temp1);
    }
    recursiveSortList(list, start + 1);
}

size_t PmergeMe::findLowValVec(const std::vector<int>& vec, size_t start) {
    size_t  lowValIndex = start;
    for (size_t  i = start + 1; i < vec.size(); i++) {
        if (vec[i] < vec[lowValIndex]) {
            lowValIndex = i;
        }
    }
    return lowValIndex;
}

void PmergeMe::recursiveSortVec(std::vector<int>& vec, size_t start) {
    if ((size_t)start >= vec.size() - 1) {
        return;
    }
    size_t  minIndex = findLowValVec(vec, start);
    if (minIndex != start) {
        std::swap(vec[start], vec[minIndex]);
    }
    recursiveSortVec(vec, start + 1);
}

std::vector<int> PmergeMe::splitVals_vec(std::vector<int> &vec){
	if (vec.empty())
		std::cout << "no vec" << std::endl;
	int len = (vec.size());
	std::vector<int> l;
	for (int i = 0; i < len / 2; i++){
		l.push_back(vec.back());
		vec.pop_back();
	}
	return l;
}

std::list<int> PmergeMe::splitVals_list(std::list<int> &list){
	if (list.empty())
		std::cout << "no list" << std::endl;
	int len = (list.size());
	std::list<int> l;
	for (int i = 0; i < len / 2; i++){
		l.push_back(list.back());
		list.pop_back();
	}
	return l;
}

void PmergeMe::sortpairs_vec(std::vector<int> &vec1, std::vector<int> &vec2){
    int temp;
    for (size_t i = 0; i < vec1.size(); i++) {
        if (vec1[i] < vec2[i]) {
            temp = vec2[i];
            vec2[i] = vec1[i];
            vec1[i] = temp;
        }
    }
}

void PmergeMe::sortpairs_list(std::list<int> &list1, std::list<int> &list2){
    int temp;
    PmergeMe p;
    for (size_t i = 0; i < list1.size(); i++) {
        if (listGet(list1, i) < listGet(list2, i)) {
            temp = listGet(list2, i);
            p.listSet(list2, i, p.listGet(list1, i));
            p.listSet(list1, i, temp);
        }
    }
}

void PmergeMe::recursiveSortPairs_vec(std::vector<int> &vec1, std::vector<int> &vec2, size_t start){
    if ((size_t)start >= vec1.size() - 1) {
        return;
    }
    size_t  minIndex = findLowValVec(vec1, start);
    if (minIndex != start) {
        std::swap(vec1[start], vec1[minIndex]);
        std::swap(vec2[start], vec2[minIndex]);
    }
    recursiveSortPairs_vec(vec1, vec2, start + 1);
}

void PmergeMe::recursiveSortPairs_list(std::list<int> &list1, std::list<int> &list2, size_t start){
    if ((size_t)start >= list1.size() - 1) {
        return;
    }
    int     temp = 0; 
    size_t  minIndex = findLowValList(list1, start);
    if (minIndex != start) {
        temp = listGet(list1, minIndex);
        listSet(list1, minIndex, listGet(list1, start));
        listSet(list1, start, temp);
        temp = listGet(list2, minIndex);
        listSet(list2, minIndex, listGet(list2, start));
        listSet(list2, start, temp);
    }
    recursiveSortPairs_list(list1, list2, start + 1);
}

int PmergeMe::binarySearch_vec(std::vector<int> vec, int item, int low, int high) {
   if (high <= low){
        return (item > vec[low])? (low + 1): low;
    }
    int mid = (low + high)/2;
    if(item == vec[mid])
        return mid+1;
    if(item > vec[mid])
        return binarySearch_vec(vec, item, mid+1, high);
    return binarySearch_vec(vec, item, low, mid-1);
}

int PmergeMe::binarySearch_list(std::list<int> list, int item, int low, int high) {
    if (high <= low){
        return (item > listGet(list, low))? (low + 1): low;
    }
    int mid = (low + high)/2;
    if(item == listGet(list, mid))
        return mid+1;
    if(item > listGet(list, mid))
        return binarySearch_list(list, item, mid+1, high);
    return binarySearch_list(list, item, low, mid-1);
}

void PmergeMe::BinaryInsertionSort_vec(std::vector<int> &to, std::vector<int> &from, int n) {  
    int loc = binarySearch_vec(to, from[n], 0, to.size() - 1);
    to.insert(to.begin() + loc, from[n]); 
}

void PmergeMe::BinaryInsertionSort_list(std::list<int> &to, std::list<int> &from, int n) { 
    int loc = binarySearch_list(to, listGet(from, n), 0, to.size() - 1);
    auto pos = to.begin();
    advance(pos, loc);
    to.insert(pos, listGet(from, n));
}

long getJacobsthal(long n){
    if (n <= 0)
        return (0);
    if (n == 1)
        return (1);
    else
       return (getJacobsthal(n - 1) + (2 * getJacobsthal(n - 2)));
}

std::vector<int> PmergeMe::fill_jacobsthall(int max_val){
	std::vector<int> vec;
	int n = 3;
	while (n < (max_val * 2)){
		vec.push_back(getJacobsthal(n));
		if (vec[vec.size() - 1] >= (max_val * 2))
			n = (max_val * 2);
		n++;
	}
	return (vec);
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& v) 
{ 
    PmergeMe p;
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i) {
        os << p.listGet(v, i); 
        if (i != (int)v.size() - 1) 
            os << ", "; 
    }
    os << "]" << std::endl;
    return os; 
}

std::vector<int> &PmergeMe::ford_johnson_vector(std::vector<int> &vec1){
    
    PmergeMe            p;
    std::vector<int>    vec2;
    std::vector<int>    Jacobsthal;
    int                 vecsize = vec1.size() / 2;
    int                 tempval = 0;
    int                 prev_jacob = 1;
    int                 index = 3;
    int                 jac = 0;
    
    vec2 = p.splitVals_vec(vec1);
	if (vec2.size() < vec1.size()){
		tempval = vec1[vec1.size() - 1];
		vec1.pop_back();
	}
	Jacobsthal = p.fill_jacobsthall(vecsize * 2);
	p.sortpairs_vec(vec1, vec2);
	p.recursiveSortPairs_vec(vec1, vec2, 0);
	vec1.insert(vec1.begin(), vec2[0]);
	while(index < (vecsize * 3)){
		while (index > prev_jacob){
			if(index <= vecsize){
				p.BinaryInsertionSort_vec(vec1, vec2, (index - 1));
            }
			index--;
		}
		if (Jacobsthal[jac])
		    prev_jacob = Jacobsthal[jac];
		index = Jacobsthal[jac + 1];
		jac++;
	}
	if (tempval){
		index = p.binarySearch_vec(vec1, tempval, 0, vec1.size());
		vec1.insert(vec1.begin() + (index - 1), tempval);
	}
    return (vec1);
}

std::list<int> &PmergeMe::ford_johnson_list(std::list<int> &list1){
    
    PmergeMe            p;
    std::list<int>      list2;
    std::vector<int>    Jacobsthal;
    std::list<int>      Jacobs_list;
    int                 listsize = list1.size() / 2;
    int                 tempval = 0;
    int                 prev_jacob = 1;
    int                 index = 3;
    int                 jac = 0;
    
    list2 = p.splitVals_list(list1);
	if (list2.size() < list1.size()){
		tempval = p.listGet(list1, list1.size() - 1);
		list1.pop_back();
	}
	Jacobsthal = p.fill_jacobsthall(listsize * 2);
    // for (auto i : Jacobsthal){
    //     Jacobs_list.push_back(Jacobsthal[i]);
    // }
	p.sortpairs_list(list1, list2);
	p.recursiveSortPairs_list(list1, list2, 0);
	list1.insert(list1.begin(), p.listGet(list2, 0));
	while(index < (listsize * 3)){
		while (index > prev_jacob){
			if(index <= listsize){
				p.BinaryInsertionSort_list(list1, list2, (index - 1));
            }
			index--;
		}
        if (Jacobsthal[jac])
		    prev_jacob = Jacobsthal[jac];
		index = Jacobsthal[jac + 1];
        // if (listGet(Jacobs_list, jac))
		//     prev_jacob = listGet(Jacobs_list, jac);
		// index = listGet(Jacobs_list, jac + 1);
		jac++;
	}
	if (tempval){
        int loc = binarySearch_list(list1, tempval, 0, list1.size() - 1);
        auto pos = list1.begin();
        advance(pos, loc);
        list1.insert(pos, tempval);
    }
    return (list1);
}

PmergeMe::~PmergeMe(){};