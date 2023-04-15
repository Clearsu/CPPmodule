/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:36:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 01:08:49 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Floor.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Floor::Floor()
{
	for (int i = 0; i < MAXITEM; i++)
		_dropped[i] = NULL;
}

Floor::Floor(const Floor& c)
{
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
}

AMateria*	Floor::unsetDropped(int idx)
{
	AMateria*	temp;

	if (idx < 0 || idx > 9 || _dropped[idx] == NULL)
		return NULL;
	temp = _dropped[idx];
	_dropped[idx] = NULL;
	return temp;
}
