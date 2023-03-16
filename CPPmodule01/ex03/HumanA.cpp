/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:16:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 21:34:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

const std::string	&HumanA::getName(void) {
	const std::string	&ref = name;
	return (ref);
}

void	HumanA::attack(void) {
	std::cout << getName() << " has attacked with " << weapon->getType() << std::endl;
}
