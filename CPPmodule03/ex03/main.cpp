/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 15:02:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "### testing constructor and destructor calls ###" << std::endl;
	{
		DiamondTrap a("hello");
		DiamondTrap b(a);
		DiamondTrap c("yes");
		c = b;
	}
	std::cout << std::endl;
	std::cout << "### checking attributes ###" << std::endl;
	{
		DiamondTrap a("jincpark");
		std::cout << "hit points: " << a.getHitPoints() << std::endl;
		std::cout << "energy points: " << a.getEnergyPoints() << std::endl;
		std::cout << "attack damage: " << a.getAttackDamage() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "### checking actions ###" << std::endl;
	{
		{
			DiamondTrap a("jincpark");
			a.attack("a tree");
			a.takeDamage(100);
			a.beRepaired(100);
		}
		ClapTrap *test1 = new ClapTrap("test1");
		ClapTrap *test2 = new ScavTrap("test2");
		ClapTrap *test3 = new FragTrap("test3");
		ClapTrap *test4 = new DiamondTrap("test4");
		test1->attack("a frog");
		test2->attack("a frog");
		test3->attack("a frog");
		test4->attack("a frog");
		delete test1;
		delete test2;
		delete test3;
		delete test4;
	}
	std::cout << std::endl;
	std::cout << "### checking own member function ###" << std::endl;
	{
		DiamondTrap a("jincpark");
		a.whoAmI();
	}
	return 0;
}
