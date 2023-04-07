/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/07 12:59:49 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

// OCF
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = "nobody";
	initHitPoints();
	initEnergyPoints();
	initAttackDamage();
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor of " << _name << " called" << std::endl;
}

// string constructor
DiamondTrap::DiamondTrap(const std::string name)
	: ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap string constructor called" << std::endl;
	_name = name;
	setName(name + "_clap_name");
	initHitPoints();
	initEnergyPoints();
	initAttackDamage();
}

// initializer
void	DiamondTrap::initHitPoints(void) {
	FragTrap::initHitPoints();
}

void	DiamondTrap::initEnergyPoints(void) {
	ScavTrap::initEnergyPoints();
}

void	DiamondTrap::initAttackDamage(void) {
	FragTrap::initAttackDamage();
}

// actions
void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	if (getHitPoints() <= amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << "DiamondTrap " << _name << " has taken damage of " \
		<< amount << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() == 0) {
		std::cout << "Repair failed: DiamondTrap " << _name \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (getHitPoints() == 0) {
		std::cout << "Repair failed: DiamondTrap " << _name \
			<< " has too low hit point" << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	setHitPoints(getHitPoints() + amount);
	std::cout << "DiamondTrap " << _name << " has repaired itself of " \
		<< amount << " hit point" << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "ClapTrap name: " << getName() << std::endl;
	std::cout << "DiamondTrap name: " << _name << std::endl;
}
