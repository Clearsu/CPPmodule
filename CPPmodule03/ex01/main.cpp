/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 21:09:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "### testing constructor and destructor calls ###" << std::endl;
	{
		ScavTrap test("test");
	}
	std::cout << std::endl;
	std::cout << "### testing virtual functions ###" << std::endl;
	{
		ClapTrap a("jincpark");
		ScavTrap b("sechung");
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
		ScavTrap a("jincpark");
		a.guardGate();
	}
	return 0;
}
