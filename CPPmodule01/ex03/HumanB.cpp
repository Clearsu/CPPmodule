/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:28:40 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 21:33:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &newWeapon) {
	weapon = &newWeapon;
}

const std::string	&HumanB::getName(void) {
	const std::string	&ref = name;
	return (ref);
}

void	HumanB::attack(void) {
	std::cout << getName() << " has attacked with " << weapon->getType() << std::endl;
}
