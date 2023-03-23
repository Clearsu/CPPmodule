/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:16:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/23 20:29:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

const std::string	&HumanA::getName(void) {
	return (name);
}

void	HumanA::attack(void) {
	std::cout << getName() << " has attacked with " << weapon->getType() << std::endl;
}
