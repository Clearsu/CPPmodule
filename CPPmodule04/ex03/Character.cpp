/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:33:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 01:08:23 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character() : _name(NULL)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & c) : _name(c._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (c._inventory[i])
		{
			if (c._inventory[i]->getType() == "ice")
				_inventory[i] = new Ice();
			else
				_inventory[i] = new Cure();
		}
		else
			_inventory[i] = NULL;
	}
}

Character::Character(std::string const name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character&	Character::operator=(Character const & c)
{
	if (this == &c)
		return *this;
	this->~Character();
	new (this) Character(c);
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &	Character::getName(void) const { return _name; }

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
	delete _inventory[idx];
	_inventory[idx] = NULL;
}
