/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 18:06:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/******************** OCF ********************/
Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_rawBits = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	_rawBits = value;
	_rawBits = _rawBits << _fracBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	_rawBits = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed& f) {
	std::cout << "Copy constructor called\n";
	_rawBits = f._rawBits;
}

void	Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called\n";
	_rawBits = f._rawBits;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
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

/******************** relational operators ********************/
bool	operator>(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits > f2._rawBits)
		return (true);
	return (false);
}

bool	operator<(const Fixed& f, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (true);
	return (false);
}

bool	operator>=(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits >= f2._rawBits)
		return (true);
	return (false);
}

bool	operator<=(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits <= f2._rawBits)
		return (true);
	return (false);
}

bool	operator==(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits == f2._rawBits)
		return (true);
	return (false);
}

bool	operator!=(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits != f2._rawBits)
		return (true);
	return (false);
}

/******************** min and max member functions ********************/
int	operator+(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits + f2._rawBits);
}

int	operator-(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits - f2._rawBits);
}

int	operator*(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits * f2._rawBits);
}

int	operator/(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits / f2._rawBits);
}
std::ostream&	operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return (os);
}
