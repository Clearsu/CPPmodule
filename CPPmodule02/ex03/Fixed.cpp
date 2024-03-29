/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 18:04:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/******************** OCF ********************/
Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const Fixed &f) : _rawBits(f._rawBits) {}

Fixed&	Fixed::operator=(const Fixed &f) {
	_rawBits = f._rawBits;
	return (*this);
}

Fixed::~Fixed() {}

/******************** other constructors ********************/
Fixed::Fixed(const int value) {
	_rawBits = value;
	_rawBits = _rawBits << _fracBits;
}

Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << _fracBits));
}

/******************** basic member functions ********************/
int	Fixed::getRawBits(void) const {
	return _rawBits;
}

void	Fixed::setRawBits(int const rawBits) {
	_rawBits = rawBits;
}

float	Fixed::toFloat(void) const {
	return (float(_rawBits) / (1 << _fracBits));
}

int	Fixed::toInt(void) const {
	return (_rawBits >> _fracBits);
}

/******************** overloading relational operators ********************/
bool	Fixed::operator>(const Fixed& f) {
	if (this->_rawBits > f._rawBits)
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed& f) {
	if (this->_rawBits < f._rawBits)
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed& f) {
	if (this->_rawBits >= f._rawBits)
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed& f) {
	if (this->_rawBits <= f._rawBits)
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed& f) {
	if (this->_rawBits == f._rawBits)
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& f) {
	if (this->_rawBits != f._rawBits)
		return true;
	return false;
}

/******************** overloading arithmetic operators ********************/
Fixed	Fixed::operator+(const Fixed& f) {
	Fixed	result;

	result._rawBits = this->_rawBits + f._rawBits;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& f) {
	Fixed	result;

	result._rawBits = this->_rawBits - f._rawBits;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& f) {
	Fixed	result;

	result._rawBits = (this->_rawBits * f._rawBits) >> this->_fracBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& f) {
	Fixed	result;

	result._rawBits = (this->_rawBits << this->_fracBits) / f._rawBits;
	return (result);
}

/******************** min and max member functions ********************/
Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return f1;
	return f2;
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return f1;
	return f2;
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return f2;
	return f1;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return f2;
	return f1;
}

/******************** overloading increment and decrement operators ********************/
Fixed	Fixed::operator++(void) {
	_rawBits += 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp;

	temp._rawBits = _rawBits;
	_rawBits += 1;
	return temp;
}

Fixed	Fixed::operator--(void) {
	_rawBits -= 1;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp;

	temp._rawBits = this->_rawBits;
	_rawBits -= 1;
	return temp;
}

/******************** overloading operator << ********************/
std::ostream&	operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}
