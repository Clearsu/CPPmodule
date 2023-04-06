/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:54:43 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 21:07:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/****************************** OCF ******************************/
FragTrap::FragTrap()
	: _name("nobody"), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& s)
	: _name(s._name), _hitPoints(s._hitPoints), \
		  _energyPoints(s._energyPoints), _attackDamage(s._attackDamage)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& s)
{
	this->~FragTrap();
	new (this) FragTrap(s);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor of " << _name << " called" << std::endl;
}

/*************************** string constructor ***************************/
FragTrap::FragTrap(const std::string name) :
	_name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "FragTrap string constructor called" << std::endl;
}

/*************************** getter ***************************/
const std::string&	FragTrap::getName(void) const {
	return _name;
}

unsigned int	FragTrap::getAttackDamage(void) const {
	return _attackDamage;
}

/*********************** actions ***********************/
void	FragTrap::attack(const std::string& target) {
	if (_energyPoints == 0) {
		std::cout << "Attack failed: FragTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoints == 0) {
		std::cout << "Attack failed: FragTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "FragTrap " << _name << " attacks " << target \
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "FragTrap " << _name << " has taken damage of " \
		<< amount << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0) {
		std::cout << "Repair failed: FragTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (_hitPoints == 0) {
		std::cout << "Repair failed: FragTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "FragTrap " << _name << " has repaired itself of " \
		<< amount << " hit point" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests you a high-five!" << std::endl;
}
