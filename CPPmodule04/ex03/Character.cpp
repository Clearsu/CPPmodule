/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:33:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/14 04:27:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(NULL)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & c) : _name(c._name)
{
	std::cout << "Character copy constructor called" << std::endl;
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
	std::cout << "Character string constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character&	Character::operator(Character const & c)
{
	if (this != &c)
	{
		this->~Character();
		new (this) Character(c);
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Chararter destructor of " << _name << " called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &	Character::getName(void) const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _name << " has equiped " << m.getType() << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	std::cout << _name << " has unequiped " << _inventory[idx]->getType() << std::endl;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	if (_inventory[idx].getType() == "ice")
		Ice::use(target);
	else
		Cure::use(target);
	delete _inventory[idx];
	_inventory[idx] = NULL;
}
