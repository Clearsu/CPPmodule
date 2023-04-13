/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 14:58:04 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "### testing basic features ###" << std::endl;
	{
		{
			FragTrap test1("test1");
			FragTrap test2(test1);
			std::cout << test2.getHitPoints() << std::endl;
			std::cout << test2.getEnergyPoints() << std::endl;
			std::cout << test2.getAttackDamage() << std::endl;
		}
		ClapTrap *test1 = new ClapTrap("test1");
		ClapTrap *test2 = new FragTrap("test2");
		test1->attack(test2->getName());
		test2->attack(test1->getName());
		delete test1;
		delete test2;
	}
	std::cout << std::endl;
	std::cout << "### testing virtual functions ###" << std::endl;
	{
		ClapTrap a("jincpark");
		FragTrap b("sechung");
		a.attack(b.getName());
		b.takeDamage(a.getAttackDamage());
		b.beRepaired(a.getAttackDamage());
		b.attack(a.getName());
		a.takeDamage(b.getAttackDamage());
		a.beRepaired(10);
	}
	std::cout << std::endl;
	std::cout << "### testing derived class's own function ###" << std::endl;
	{
		FragTrap a("jincpark");
		a.highFivesGuys();
	}
	return 0;
}
