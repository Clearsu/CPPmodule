/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:03:47 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/06 16:37:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <limits>

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : maxSize(N), currSize(0) {}

Span::Span(const Span& src)
	: vec(src.vec), maxSize(src.maxSize), currSize(src.currSize) {}

Span& Span::operator=(const Span& src) {
	this->vec = src.vec;
	this->maxSize = src.maxSize;
	this->currSize = src.currSize;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int const n) {
	if (currSize == maxSize)
		throw Span::MaxSizeException();
	this->vec.push_back(n);
	++this->currSize;
}

unsigned int Span::shortestSpan(void) {
	if (this->currSize == 0 || this->currSize == 1)
		throw Span::CannotCalculateSpanException();

	std::vector<int> sorted(this->vec);
	std::vector<int>::iterator begin = this->vec.begin();
	std::vector<int>::iterator end = this->vec.end();
	unsigned int	shortest = std::numeric_limits<unsigned int>::max();
	unsigned int	diff;

	std::sort(begin, end);
	for (std::vector<int>::const_iterator it = begin;
			it != end - 1; ++it) {
		diff = *(it + 1) - *it;
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan(void) {
	if (this->currSize == 0 || this->currSize == 1)
		throw Span::CannotCalculateSpanException();

	int max = *(std::max_element(this->vec.begin(), this->vec.end()));
	int min = *(std::min_element(this->vec.begin(), this->vec.end()));

	return max - min;
}

void	Span::addSequence(std::vector<int>::const_iterator begin, \
		std::vector<int>::const_iterator end) {
	for (std::vector<int>::const_iterator it = begin; it != end; ++it)
		this->addNumber(*it);
}

const char * Span::MaxSizeException::what(void) const throw() {
	return "exception occurred: can not add more value";
}

const char * Span::CannotCalculateSpanException::what(void) const throw() {
	return "exception occurred: can not calculate span: span size 0 or 1";
}
