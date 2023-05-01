/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/01 21:30:40 by jincpark         ###   ########.fr       */
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

PmergeMe*	PmergeMe::getInstance(int argc, char** argv) {
	if (PmergeMe::instance == 0)
		PmergeMe::instance = new PmergeMe(argc, argv);
	return PmergeMe::instance;
}

void	PmergeMe::deleteInstance(void) {
	delete PmergeMe::instance;
}
