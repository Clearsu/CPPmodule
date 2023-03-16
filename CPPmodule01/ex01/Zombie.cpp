/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:58:54 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 17:42:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void	Zombie::setName(std::string str) {
	name = str;
}