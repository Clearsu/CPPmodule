/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 15:21:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	/********** ClapTrap **********/
	ClapTrap a("jincpark");
	ClapTrap b("sechung");
	ClapTrap c;
	ClapTrap d;

	// testing copy constructor and copy assignment constructor
	c = ClapTrap(a);

	// testing actions
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	d.takeDamage(1000000);
	d.attack(a.getName());
	d.beRepaired(10);

	/********** ScavTrap **********/

	return 0;
}
