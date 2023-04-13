/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:40:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 17:23:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

// Orthodox Canonical Form
Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	_brain = new Brain("I want a fish");
}

Cat::Cat(const Cat& c) : Animal(c)
{
	std::cout << "Cat copy constructor called" << std::endl;
	setType("Cat");
	_brain = new Brain(*c._brain);
}

Cat&	Cat::operator=(const Cat& c)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &c)
	{
		Animal::operator=(c);
		*_brain = *c._brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

// string constructor
Cat::Cat(const std::string& idea) : Animal()
{
	std::cout << "Cat string constructor called" << std::endl;
	setType("Cat");
	_brain = new Brain(idea);
}

// getter
const Brain&	Cat::getBrain(void) const
{
	return *_brain;
}

// overriding
void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow" << std::endl;
}
