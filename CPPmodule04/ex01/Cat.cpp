/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:40:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 22:00:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Brain.hpp"

// Orthodox Canonical Form
Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, "I want a fish");
}

Cat::Cat(const Cat& c) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	setType(c.getType());
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, c._brain->getIdea(i));
}

Cat&	Cat::operator=(const Cat& c)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	setType(c.getType());
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, c._brain->getIdea(i));
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

// overriding
void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow" << std::endl;
}
