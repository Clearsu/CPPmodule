/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/03 21:46:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap dude("sexMachine");
	ClapTrap b("sji");
	ClapTrap c;

	c = ClapTrap("jangcho");
	dude.attack("stone");
	b.attack(dude.getName());
	c.attack(b.getName());
}
