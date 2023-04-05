/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:28:40 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 17:45:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

const std::string	&HumanB::getName(void) {
	return (_name);
}

void	HumanB::attack(void) {
	std::cout << getName() << " has attacked with " << _weapon->getType() << std::endl;
}
