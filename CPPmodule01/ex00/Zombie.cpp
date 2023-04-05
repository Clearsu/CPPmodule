/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:58:54 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 17:49:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "constructor called" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "destructor of " << _name << " called" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void	Zombie::setName(std::string str) {
	_name = str;
}
