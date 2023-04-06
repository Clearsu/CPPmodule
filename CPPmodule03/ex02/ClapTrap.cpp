/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:41:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 20:18:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

/****************************** OCF ******************************/
ClapTrap::ClapTrap()
	: _name("nobody"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) : 
	_name(c._name), _hitPoints(c._hitPoints), _energyPoints(c._energyPoints),
	_attackDamage(c._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& c) {
	this->~ClapTrap();
	new (this) ClapTrap(c);
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor of " << _name << " called" << std::endl;
}

/*************************** other constructor ***************************/
ClapTrap::ClapTrap(const std::string name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

/*************************** getter ***************************/
const std::string&	ClapTrap::getName(void) const {
	return _name;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return _attackDamage;
}

/*********************** actions ***********************/
void	ClapTrap::attack(const std::string& target) {
	if (_energyPoints == 0) {
		std::cout << "Attack failed: ClapTrap " << _name \
			<< " has too low energy points" << std::endl;
		return ;
	}
	if (_hitPoints == 0) {
		std::cout << "Attack failed: ClapTrap " << _name \
			<< " has too low hit points" << std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target \
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " has taken damage of " \
		<< amount << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0) {
		std::cout << "Repair failed: ClapTrap " << _name \
			<< " has too low energy points" << std::endl;
		return ;
	}
	if (_hitPoints == 0) {
		std::cout << "Repair failed: ClapTrap " << _name \
			<< " has too low hit points" << std::endl;
		return ;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " has repaired itself of " \
		<< amount << " hit points" << std::endl;
}
