/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:12:17 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 17:32:04 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

// Orthodox Canonical Form
Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	_brain = new Brain("I want a bone");
}

Dog::Dog(const Dog& d) : Animal(d)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*d._brain);
}

Dog&	Dog::operator=(const Dog& d)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &d)
	{
		Animal::operator=(d);
		*_brain = *d._brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

// string constructor
Dog::Dog(const std::string idea)
{
	std::cout << "Dog string constructor called" << std::endl;
	_brain = new Brain(idea);
}

// getter
const Brain&	Dog::getBrain(void) const
{
	return *_brain;
}

// overriding
void	Dog::makeSound(void) const
{
	std::cout << "Dog: Bark" << std::endl;
}
