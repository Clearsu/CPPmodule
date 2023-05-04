/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:03:47 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 16:07:58 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

	std::vector<int>::const_iterator outer_loop = this->vec.begin();
	std::vector<int>::const_iterator inner_loop;
	unsigned int shortest = std::numeric_limits<unsigned int>::max();

	for (unsigned int i = 0; i < this->currSize - 1; ++i) {
		inner_loop = outer_loop + 1;
		for (unsigned int j = i + 1; j < this->currSize; ++j) {
			if (*outer_loop < *inner_loop &&
					static_cast<unsigned int>(*inner_loop - *outer_loop) < shortest)
				shortest = static_cast<unsigned int>(*inner_loop - *outer_loop);
			else if (*inner_loop < *outer_loop &&
					static_cast<unsigned int>(*outer_loop - *inner_loop) < shortest)
				shortest = static_cast<unsigned int>(*outer_loop - *inner_loop);
			++inner_loop;
		}
		++outer_loop;
	}
	return shortest;
}

unsigned int Span::longestSpan(void) {
	if (this->currSize == 0 || this->currSize == 1)
		throw Span::CannotCalculateSpanException();

	std::vector<int>::const_iterator it = this->vec.begin();
	int min = *it;
	int max = *it;

	for (unsigned int i = 0; i < this->currSize; ++i)
	{
		if (*it < min)
			min = *it;
		else if (*it > max)
			max = *it;
		++it;
	}
	return static_cast<unsigned int>(max - min);
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
