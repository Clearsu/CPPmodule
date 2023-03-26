/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/25 08:50:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/******************** OCF ********************/
void	Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called\n";
	_rawBits = f._rawBits;
}

/******************** other constructors ********************/
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	_rawBits = value;
	_rawBits = _rawBits << _fracBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	_rawBits = roundf(value * (1 << _fracBits));
}

/******************** basic member functions ********************/
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_rawBits);
}

void	Fixed::setRawBits(int const rawBits) {
	std::cout << "setRawBits member function called\n";
	_rawBits = rawBits;
}

float	Fixed::toFloat(void) const {
	return (float(_rawBits) / (1 << _fracBits));
}

int	Fixed::toInt(void) const {
	return (_rawBits >> _fracBits);
}

/******************** overloading relational operators ********************/
bool	Fixed::operator>(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits > f2._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& f, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits >= f2._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits <= f2._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits == f2._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits != f2._rawBits)
		return (true);
	return (false);
}

/******************** overloading arithmetic operators ********************/
int	Fixed::operator+(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits + f2._rawBits);
}

int	Fixed::operator-(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits - f2._rawBits);
}

int	Fixed::operator*(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits * f2._rawBits);
}

int	Fixed::operator/(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits / f2._rawBits);
}

/******************** min and max member functions ********************/
static Fixed::Fixed&	min(Fixed& f1, Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f1);
	return (f2);
}

static Fixed::Fixed&	min(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f1);
	return (f2);
}

static Fixed::Fixed&	max(Fixed& f1, Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f2);
	return (f1);
}

static Fixed::Fixed&	max(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f2);
	return (f1);
}

/******************** overloading increment and decrement operators ********************/
Fixed	Fixed::operator++(void) {
	_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp;

	temp = *this;
	_rawBits += 1;
	return (temp);
}

Fixed	Fixed::operator--(void) {
	_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp;

	temp = *this;
	_rawBits -= 1;
	return (temp);
}

/******************** overloading operator << ********************/
std::ostream&	operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return (os);
}
