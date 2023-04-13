/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:40:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 15:06:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

// Orthodox Canonical Form
Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat& c) : Animal(c)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& c)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	setType(c.getType());
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

// overriding
void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow" << std::endl;
}
