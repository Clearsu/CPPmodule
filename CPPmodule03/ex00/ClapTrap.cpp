/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:41:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/03 21:43:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("nobody"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) : 
	_name(c._name), _hitPoint(c._hitPoint), _energyPoint(c._energyPoint),
	_attackDamage(c._attackDamage)
{
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& c) {
	this->~ClapTrap();	
	new (this) ClapTrap(c);
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "destructor of " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) :
	_name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "string constructor called" << std::endl;
}

const std::string&	ClapTrap::getName(void) {
	return _name;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << " attacks " << target \
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
}

void	ClapTrap::beRepaired(unsigned int amount) {
}
