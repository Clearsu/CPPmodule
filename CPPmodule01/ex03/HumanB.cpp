/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:28:40 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/23 20:32:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

const std::string	&HumanB::getName(void) {
	return (name);
}

void	HumanB::attack(void) {
	std::cout << getName() << " has attacked with " << weapon->getType() << std::endl;
}
