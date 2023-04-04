/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:41:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/04 22:24:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

/****************************** OCF ******************************/
ClapTrap::ClapTrap()
	: _name("nobody"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) : 
	_name(c._name), _hitPoint(c._hitPoint), _energyPoint(c._energyPoint),
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
	_name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
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
	if (_energyPoint == 0) {
		std::cout << "Attack failed: ClapTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoint == 0) {
		std::cout << "Attack failed: ClapTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoint;
	std::cout << "ClapTrap " << _name << " attacks " << target \
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoint <= amount)
		_hitPoint = 0;
	else
		_hitPoint -= amount;
	std::cout << "ClapTrap " << _name << " has taken damage of " \
		<< amount << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoint == 0) {
		std::cout << "Repair failed: ClapTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoint == 0) {
		std::cout << "Repair failed: ClapTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoint;
	_hitPoint += amount;
	std::cout << "ClapTrap " << _name << " has repaired itself of " \
		<< amount << " hit point" << std::endl;
}
