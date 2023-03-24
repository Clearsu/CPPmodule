/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:28:40 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 20:23:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

const std::string	&HumanB::getName(void) {
	return (_name);
}

void	HumanB::attack(void) {
	std::cout << getName() << " has attacked with " << _weapon->getType() << std::endl;
}
