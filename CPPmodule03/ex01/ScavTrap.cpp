/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 15:20:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/****************************** OCF ******************************/
ScavTrap::ScavTrap()
	: _name("nobody"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s) :
	: _name(s._name), _hitPoints(s._hitPoints), _energyPoints(s._energyPoints), _attackDamage(s._attackDamage)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& s)
{
	this->~ScavTrap();
	new (this) ScavTrap(s);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor of " << _name << " called" << std::endl;
}

/*************************** other constructor ***************************/
ScavTrap::ScavTrap(const std::string name) :
	_name(name), _hitPoint(100), _energyPoint(50), _attackDamage(20)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
}

/*********************** actions ***********************/
void	ScavTrap::guardGate(void)
{
	std::cout << "Now ScavTrap " << _name << " has turn to gate guard mode" << std::endl;
}
