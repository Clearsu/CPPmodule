/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/20 18:07:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called\n";
	_value = f._value;
}

void	Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called\n";
	_value = f._value;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}
