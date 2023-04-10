/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:28:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 16:53:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

// orthodox canonical form
Animal::Animal() : type("animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& a) : type(a.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& a)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = a.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// getter
const std::string&	Animal::getType(void) const
{
	return type;
}

// setter
void	Animal::setType(const std::string& type)
{
	this->type = type;
}

// polymorphism
void	Animal::makeSound(void) const
{
	std::cout << "Animal: What does the animal say" << std::endl;
}
