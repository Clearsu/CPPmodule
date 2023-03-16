/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:31:57 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 21:33:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void) {
	{
		Weapon	club = Weapon("crued spiked club");
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("broken club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crued spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("broken club");
		jim.attack();
	}
	return (0);
}
