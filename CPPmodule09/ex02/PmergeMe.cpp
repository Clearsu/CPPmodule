/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/01 15:26:11 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cerrno>
#include <stdexcept>
#include <PmergeMe.hpp>

PmergeMe*	PmergeMe::instance = 0;

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int argc, char** argv) {
	parseArgv(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe& src) { (void)src; }
PmergeMe& PmergeMe::operator=(const PmergeMe& src) { (void)src; return *this; }
PmergeMe::~PmergeMe() {}

void	PmergeMe::parseArgv(int argc, char** argv) {
	char*		endptr = 0;
	long		value;

	for (int i = 1; i < argc; ++i) {
		value = std::strtol(argv[i], &endptr, 10);
		if (value <= 0 || value != static_cast<int>(value) 
				|| *endptr != '\0' || errno == ERANGE)
			throw std::runtime_error("Error: bad argument: " + std::string(argv[i]));
		this->vec.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::mergeInsertionSort(std::vector<int>::iterator start, std::vector<int>::iterator finish) {
	if (finish - start < 10)
		insertionSortVector(start, finish);
	else {
		
	}
}

void	PmergeMe::insertionSortVector(std::vector<int>::iterator start, std::vector<int>::iterator finish) {
	std::vector<int>::iterator	it_i, it_j;
	int	key;

	it_i = start + 1;
	while (it_i != finish) {
		key = *it_i;
		it_j = it_i - 1;
		while (it_j >= start && *it_j > key) {
			*(it_j + 1) = *it_j;
			--it_j;
		}
		*(it_j + 1) = key;
		++it_i;
	}
}

PmergeMe*	PmergeMe::getInstance(int argc, char** argv) {
	if (PmergeMe::instance == 0)
		PmergeMe::instance = new PmergeMe(argc, argv);
	return PmergeMe::instance;
}

void	PmergeMe::deleteInstance(void) {
	delete PmergeMe::instance;
}

void	PmergeMe::sort(void) {
	mergeInsertionSort(this->vec_src.begin(), this->vec_src.end());
}

void	PmergeMe::printSrcVector(void) {
	std::vector<int>::iterator it = this->vec_src.begin();
	std::vector<int>::iterator end = this->vec_src.end();

	while (it != end)
		std::cout << *(it++) << " ";
	std::cout << std::endl;
}

void	PmergeMe::printDestVector(void) {
	std::vector<int>::iterator it = this->vec_dest.begin();
	std::vector<int>::iterator end = this->vec_dest.end();

	while (it != end)
		std::cout << *(it++) << " ";
	std::cout << std::endl;
}
