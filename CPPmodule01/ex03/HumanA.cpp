/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:16:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 20:22:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

const std::string&	HumanA::getName(void) {
	return (_name);
}

void	HumanA::attack(void) {
	std::cout << getName() << " has attacked with " << _weapon.getType() << std::endl;
}
