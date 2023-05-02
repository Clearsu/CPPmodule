/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/02 16:13:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cerrno>
#include <stdexcept>

#include <sys/time.h>

#include "PmergeMe.hpp"

PmergeMe*	PmergeMe::instance = 0;

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int argc, char** argv) {
	checkArgc(argc, argv);
	parseArgv(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe& src) { (void)src; }
PmergeMe& PmergeMe::operator=(const PmergeMe& src) { (void)src; return *this; }
PmergeMe::~PmergeMe() {}

void	PmergeMe::checkArgc(int argc, char** argv) {
	std::size_t	count;
	std::size_t	maxInt;

	if (argc == 1)
		throw std::runtime_error("Error: no argument");
	count = 0;
	maxInt = static_cast<std::size_t>(std::numeric_limits<int>::max());
	while (*(argv++)) {
		++count;
		if (count > maxInt) {
			throw std::runtime_error("Error: too many arguments");
		}
	}
}

void	PmergeMe::parseArgv(int argc, char** argv) {
	char*		endptr = 0;
	long		value;

	for (int i = 1; i < argc; ++i) {
		value = std::strtol(argv[i], &endptr, 10);
		if (value <= 0 || value != static_cast<int>(value) 
				|| *endptr != '\0' || errno == ERANGE) {
			throw std::runtime_error("Error: bad argument: " + std::string(argv[i]));
		}
		this->vec.push_back(static_cast<int>(value));
		this->deq.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::mergeInsertionSortVector(int left, int right) {
	int	mid;

	if (right - left <= INSERTION_N) {
		insertionSortVector(left, right);
		return ;
	}
	mid = (left + right) / 2;
	mergeInsertionSortVector(left, mid);
	mergeInsertionSortVector(mid + 1, right);
	mergeVector(left, mid, right);
}

void	PmergeMe::insertionSortVector(int left, int right) {
	int	outer_idx;
	int	inner_idx;
	int			key;

	for (outer_idx = left + 1; outer_idx <= right; ++outer_idx) {
		key = this->vec[outer_idx];
		inner_idx = outer_idx - 1;
		while (inner_idx >= left && this->vec[inner_idx] > key) {
			this->vec[inner_idx + 1] = this->vec[inner_idx];
			--inner_idx;
		}
		this->vec[inner_idx + 1] = key;
	}
}

void	PmergeMe::mergeVector(int left, int mid, int right) {
	int			left_idx;
	int			right_idx;
	int			recopy_idx;
	int			temp_idx;

	left_idx = left;
	right_idx = mid + 1;

	while (left_idx <= mid && right_idx <= right) {
		if (this->vec[left_idx] < this->vec[right_idx]) {
			this->vec_temp.push_back(this->vec[left_idx]);
			++left_idx;
		}
		else {
			this->vec_temp.push_back(this->vec[right_idx]);
			++right_idx;
		}
	}

	while (left_idx <= mid) {
		this->vec_temp.push_back(this->vec[left_idx]);
		++left_idx;
	}

	while (right_idx <= right) {
		this->vec_temp.push_back(this->vec[right_idx]);
		++right_idx;
	}

	temp_idx = 0;
	for (recopy_idx = left; recopy_idx <= right; ++recopy_idx) {
		this->vec[recopy_idx] = this->vec_temp[temp_idx];
		++temp_idx;
	}

	this->vec_temp.clear();
}

void	PmergeMe::mergeInsertionSortDeque(int left, int right) {
	int	mid;

	if (right - left < INSERTION_N) {
		insertionSortDeque(left, right);
		return ;
	}
	mid = (left + right) / 2;
	mergeInsertionSortDeque(left, mid);
	mergeInsertionSortDeque(mid + 1, right);
	mergeDeque(left, mid, right);
}

void	PmergeMe::insertionSortDeque(int left, int right) {
	int	outer_idx;
	int	inner_idx;
	int			key;

	for (outer_idx = left + 1; outer_idx <= right; ++outer_idx) {
		key = this->deq[outer_idx];
		inner_idx = outer_idx - 1;
		while (inner_idx >= left && this->deq[inner_idx] > key) {
			this->deq[inner_idx + 1] = this->deq[inner_idx];
			--inner_idx;
		}
		this->deq[inner_idx + 1] = key;
	}
}

void	PmergeMe::mergeDeque(int left, int mid, int right) {
	int			left_idx;
	int			right_idx;
	int			recopy_idx;
	int			temp_idx;

	left_idx = left;
	right_idx = mid + 1;

	while (left_idx <= mid && right_idx <= right) {
		if (this->deq[left_idx] < this->deq[right_idx]) {
			this->deq_temp.push_back(this->deq[left_idx]);
			++left_idx;
		}
		else {
			this->deq_temp.push_back(this->deq[right_idx]);
			++right_idx;
		}
	}

	while (left_idx <= mid) {
		this->deq_temp.push_back(this->deq[left_idx]);
		++left_idx;
	}

	while (right_idx <= right) {
		this->deq_temp.push_back(this->deq[right_idx]);
		++right_idx;
	}

	temp_idx = 0;
	for (recopy_idx = left; recopy_idx <= right; ++recopy_idx) {
		this->deq[recopy_idx] = this->deq_temp[temp_idx];
		++temp_idx;
	}

	this->deq_temp.clear();
}

PmergeMe*	PmergeMe::getInstance(int argc, char** argv) {
	if (PmergeMe::instance == 0) {
		PmergeMe::instance = new PmergeMe(argc, argv);
	}
	return PmergeMe::instance;
}

void	PmergeMe::deleteInstance(void) {
	delete PmergeMe::instance;
}

void	PmergeMe::sortVector(void) {
	mergeInsertionSortVector(0, this->vec.size() - 1);
}

void	PmergeMe::sortDeque(void) {
	mergeInsertionSortDeque(0, this->vec.size() - 1);
}

std::time_t	PmergeMe::getCurrentTimeMicrosec(void) {
	struct timeval	currentTime;

	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * 1000000UL + currentTime.tv_usec;
}

void	PmergeMe::printVector(const char* str, const char* color) const {
	int	totalSize;

	std::cout << color << str;
	totalSize = static_cast<int>(this->vec.size());
	for (int idx = 0; idx < totalSize; ++idx) {
		std::cout << this->vec[idx] << " ";
	}
	std::cout << std::endl;
}

std::size_t	PmergeMe::getVectorSize(void) const {
	return this->vec.size();
}

std::size_t	PmergeMe::getDequeSize(void) const {
	return this->deq.size();
}

void	PmergeMe::isSorted(void) const {

	int	ivec = 0;
	int	ivecEnd = this->vec.size() - 1;
	int	ideq = 0;
	int ideqEnd = this->deq.size() - 1;

	while (ivec < ivecEnd) {
		if (this->vec[ivec] > this->vec[ivec + 1])
			throw std::runtime_error("Error: std::vector unsorted");
		++ivec;
	}
	while (ideq < ideqEnd) {
		if (this->deq[ideq] > this->deq[ideq + 1])
			throw std::runtime_error("Error: std::vector unsorted");
		++ideq;
	}
}
