/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 01:18:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

/****************************** OCF ******************************/
ScavTrap::ScavTrap()
	: _name("nobody"), _hitPoint(100), _energyPoint(50), _attackDamage(20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
	: _name(s._name), _hitPoint(s._hitPoint), _energyPoint(s._energyPoint)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_attackDamage = s._attackDamage;
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

/*************************** getter ***************************/
const std::string&	ScavTrap::getName(void) const {
	return _name;
}

unsigned int	ScavTrap::getAttackDamage(void) const {
	return _attackDamage;
}

/*********************** actions ***********************/
void	ScavTrap::attack(const std::string& target) {
	if (_energyPoint == 0) {
		std::cout << "Attack failed: ScavTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoint == 0) {
		std::cout << "Attack failed: ScavTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoint;
	std::cout << "ScavTrap " << _name << " attacks " << target \
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoint <= amount)
		_hitPoint = 0;
	else
		_hitPoint -= amount;
	std::cout << "ScavTrap " << _name << " has taken damage of " \
		<< amount << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (_energyPoint == 0) {
		std::cout << "Repair failed: ScavTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoint == 0) {
		std::cout << "Repair failed: ScavTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoint;
	_hitPoint += amount;
	std::cout << "ScavTrap " << _name << " has repaired itself of " \
		<< amount << " hit point" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has started gate guarding" << std::endl;
}
