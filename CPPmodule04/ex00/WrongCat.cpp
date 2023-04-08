/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:34:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 16:32:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

// Orthodox Canonical Form
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& c) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	setType(c.getType());
}

WrongCat&	WrongCat::operator=(const WrongCat& c)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	setType(c.getType());
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// no subtype polymorphism
void	WrongCat::makeSound(void)
{
	std::cout << "WrongCat: Mweweeeweoweowoeow" << std::endl;
}
