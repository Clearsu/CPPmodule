/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:12:17 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 22:00:37 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

// Orthodox Canonical Form
Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, "I want a bone");
}

Dog::Dog(const Dog& d) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	setType(d.getType());
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, d._brain->getIdea(i));
}

Dog&	Dog::operator=(const Dog& d)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	setType(d.getType());
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, d._brain->getIdea(i));
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

// overriding
void	Dog::makeSound(void) const
{
	std::cout << "Dog: Bark" << std::endl;
}
