/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:36:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/15 03:56:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Floor.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Floor::Floor()
{
	std::cout << "Floor default constructor called" << std::endl;
	for (int i = 0; i < MAXITEM; i++)
		_dropped[i] = NULL;
}

Floor::Floor(const Floor& c)
{
	std::cout << "Floor copy constructor called" << std::endl;
	for (int i = 0; i < MAXITEM; i++)
	{
		if (c._dropped[i] != NULL)
		{
			if (c._dropped[i]->getType() == "ice")
				_dropped[i] = new Ice();
			else
				_dropped[i] = new Cure();
		}
		else
			_dropped[i] = NULL;
	}
}

Floor&	Floor::operator=(const Floor& c)
{
	if (this == &c)
		return *this;
	this->~Floor();
	new (this) Floor(c);
	return *this;
}

Floor::~Floor()
{
	std::cout << "Floor destructor called" << std::endl;
	for (int i = 0; i < MAXITEM; i++)
	{
		if (_dropped[i] != NULL)
			delete _dropped[i];
	}
}

void	Floor::setDropped(AMateria* m)
{
	for (int i = 0; i < MAXITEM; i++)
	{
		if (_dropped[i] == NULL)
		{
			_dropped[i] = m;
			return ;
		}
	}
	std::cout << "Too many Materias on the floor" << std::endl;
}

const AMateria*	Floor::unsetDropped(const AMateria* m)
{
	for (int i = 0; i < MAXITEM; i++)
	{
		if (_dropped[i] == m)
		{
			_dropped[i] = NULL;
			return m;
		}
	}
	std::cout << "No Materias on the floor" << std::endl;
	return NULL;
}
