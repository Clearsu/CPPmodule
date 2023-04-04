/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:58:54 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/04 21:44:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}
