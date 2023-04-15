/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 01:17:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/****************************** OCF ******************************/
FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	initHitPoints();
	initEnergyPoints();
	initAttackDamage();
}

FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& f) {
	if (this == &f)
		return *this;
	this->~FragTrap();
	new (this) FragTrap(f);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor of " << getName() << " called" << std::endl;
}

/*************************** string constructor ***************************/
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap string constructor called" << std::endl;
	initHitPoints();
	initEnergyPoints();
	initAttackDamage();
}

/**************************** initializer ***************************/
void	FragTrap::initHitPoints(void) {
	setHitPoints(100);
}

void	FragTrap::initEnergyPoints(void) {
	setEnergyPoints(100);
}

void	FragTrap::initAttackDamage(void) {
	setAttackDamage(30);
}


/*********************** actions ***********************/
void	FragTrap::attack(const std::string& target) {
	if (getEnergyPoints() == 0) {
		std::cout << "Attack failed: FragTrap " << getName() \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (getHitPoints() == 0) {
		std::cout << "Attack failed: FragTrap " << getName() \
			<< " has too low hit point" << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target \
		<< ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (getHitPoints() <= amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << "FragTrap " << getName() << " has taken damage of " \
		<< amount << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() == 0) {
		std::cout << "Repair failed: FragTrap " << getName() \
			<< " has too low energy point" << std::endl;
		return ;
	}
	if (getHitPoints() == 0) {
		std::cout << "Repair failed: FragTrap " << getName() \
			<< " has too low hit point" << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	setHitPoints(getHitPoints() + amount);
	std::cout << "FragTrap " << getName() << " has repaired itself of " \
		<< amount << " hit point" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " has requested you a high-five!!" << std::endl;
}
