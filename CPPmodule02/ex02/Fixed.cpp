/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 22:29:53 by jincpark         ###   ########.fr       */
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

/******************** overloading arithmetic operators ********************/
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

/******************** min and max member functions ********************/
static Fixed&	min(Fixed& f1, Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f1);
	return (f2);
}

static Fixed&	min(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f1);
	return (f2);
}

static Fixed&	max(Fixed& f1, Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f2);
	return (f1);
}

static Fixed&	max(const Fixed& f1, const Fixed& f2) {
	if (f1._rawBits < f2._rawBits)
		return (f2);
	return (f1);
}

/******************** overloading increment and decrement operators ********************/
Fixed	operator++(void) {
	Fixed	temp;

	temp._rawBits = this._rawBits + 1;
	return (temp);
}

Fixed	operator++(int) {

}

Fixed	operator--(void) {
}

Fixed	operator--(int) {
}

/******************** overloading operator << ********************/
std::ostream&	operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return (os);
}
