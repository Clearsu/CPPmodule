/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:12:17 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 16:10:58 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

// Orthodox Canonical Form
Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog& d) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	setType(d.getType());
}

Dog&	Dog::operator=(const Dog& d)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	setType(d.getType());
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// overriding
void	Dog::makeSound(void)
{
	std::cout << "Dog: Bark" << std::endl;
}
