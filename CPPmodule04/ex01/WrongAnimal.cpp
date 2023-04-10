/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:41:23 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 16:53:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

// Orthodox Canonical Form
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& w) : type(w.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& w)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	type = w.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// getter
const std::string&	WrongAnimal::getType(void) const
{
	return type;
}

// setter
void	WrongAnimal::setType(const std::string type)
{
	this->type = type;
}

// no subtype polymorphism
void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal: What does the wrong animal say" << std::endl;
}
