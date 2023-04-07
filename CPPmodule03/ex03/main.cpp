/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/07 12:34:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "### testing constructor and destructor calls ###" << std::endl;
	{
		DiamondTrap a;
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
		DiamondTrap a("jincpark");
		a.attack("a tree");
		a.takeDamage(100);
		a.beRepaired(100);
	}
	std::cout << std::endl;
	std::cout << "### checking own member function ###" << std::endl;
	{
		DiamondTrap a("jincpark");
		a.whoAmI();
	}
	return 0;
}
