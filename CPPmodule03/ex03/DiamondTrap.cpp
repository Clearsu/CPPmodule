/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 22:20:55 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = ClapTrap::_name;
	ScavTrap::setName("nobody");
	FragTrap::setHitPoints(FragTrap::getHitPoints());
	ScavTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	FragTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}
