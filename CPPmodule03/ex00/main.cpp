/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/14 13:14:14 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap a("jincpark");
	ClapTrap b("sechung");
	ClapTrap c("jang-cho");
	ClapTrap d;

	// testing copy constructor and copy assignment constructor
	d = ClapTrap(a);

	// testing actions
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	for (int i = 0; i < 10; i++)
		a.attack(b.getName());
	for (int i = 0; i < 10; i++)
		b.beRepaired(10);
	d.takeDamage(1000000);
	d.attack(a.getName());
	d.beRepaired(10);

	return 0;
}
