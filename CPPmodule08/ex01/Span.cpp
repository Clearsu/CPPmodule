/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:03:47 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/27 18:21:26 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <Span.hpp>

Span::Span() : maxSize(0), currSize(0) {}
Span::Span(unsigned int N) : maxSize(N), currSize(0) {}
Span::Span(const Span& src)
	: maxSize(src.maxSize), currSize(src.currSize), vec(src.vec) {}
Span& Span::operator=(const Span& src) {
	if (this == &src)
		return *this;
	this->~Span();
	new (this) Span(src);
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

	std::vector<int>::const_iterator it_i = this->vec.begin();
	std::vector<int>::const_iterator it_j;
	unsigned int shortest = std::numeric_limits<unsigned int>::max();

	for (unsigned int i = 0; i < this->currSize - 1; ++i) {
		it_j = it_i + 1;
		for (unsigned int j = i + 1; j < this->currSize; ++j) {
			if (*it_i < *it_j && static_cast<unsigned int>(*it_j - *it_i) < shortest)
				shortest = static_cast<unsigned int>(*it_j - *it_i);
			else if (*it_j < *it_i && static_cast<unsigned int>(*it_i - *it_j) < shortest)
				shortest = static_cast<unsigned int>(*it_i - *it_j);
			++it_j;
		}
		++it_i;
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
		if (*it > max)
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
