/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/12 17:47:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

/****************************** OCF ******************************/
ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	setName("nobody");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& s) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	setName(s.getName());
	setHitPoints(s.getHitPoints());
	setEnergyPoints(s.getEnergyPoints());
	setAttackDamage(s.getAttackDamage());
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& s) {
	if (this != &s)
	{
		this->~ScavTrap();
		new (this) ScavTrap(s);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor of " << getName() << " called" << std::endl;
}

/*************************** string constructor ***************************/
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap string constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

/************************* initializer ***************************/
void	ScavTrap::initHitPoints(void) {
	setHitPoints(100);
}

void	ScavTrap::initEnergyPoints(void) {
	setEnergyPoints(50);
}

void	ScavTrap::initAttackDamage(void) {
	setAttackDamage(20);
}

/*********************** actions ***********************/
void	ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() == 0) {
		std::cout << "Attack failed: ScavTrap " << getName() \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (getHitPoints() == 0) {
		std::cout << "Attack failed: ScavTrap " << getName() \
			<< " has too low hit point" << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target \
		<< ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (getHitPoints() <= amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << "ScavTrap " << getName() << " has taken damage of " \
		<< amount << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() == 0) {
		std::cout << "Repair failed: ScavTrap " << getName() \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (getHitPoints() == 0) {
		std::cout << "Repair failed: ScavTrap " << getName() \
			<< " has too low hit point" << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	setHitPoints(getHitPoints() + amount);
	std::cout << "ScavTrap " << getName() << " has repaired itself of " \
		<< amount << " hit point" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << getName() << " has started gate guarding" << std::endl;
}
