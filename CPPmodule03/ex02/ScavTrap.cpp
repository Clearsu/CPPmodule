/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 21:05:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

/****************************** OCF ******************************/
ScavTrap::ScavTrap()
	: _name("nobody"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
	: _name(s._name), _hitPoints(s._hitPoints), \
		  _energyPoints(s._energyPoints), _attackDamage(s._attackDamage)
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
	_name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
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
	if (_energyPoints == 0) {
		std::cout << "Attack failed: ScavTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoints == 0) {
		std::cout << "Attack failed: ScavTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "ScavTrap " << _name << " attacks " << target \
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ScavTrap " << _name << " has taken damage of " \
		<< amount << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0) {
		std::cout << "Repair failed: ScavTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoints == 0) {
		std::cout << "Repair failed: ScavTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ScavTrap " << _name << " has repaired itself of " \
		<< amount << " hit point" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " has started gate guarding" << std::endl;
}
