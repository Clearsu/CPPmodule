/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 18:46:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Zombie.hpp"

void	checkLeaks(void) {
	system("leaks --list zombie");
}

int	main(void)
{
	Zombie*	a;
	Zombie	dummy;

	dummy.setName("dummyZombie");
	dummy.announce();
	a = dummy.newZombie("zombieA");
	delete a;
	dummy.randomChump("zombieB");
	atexit(checkLeaks);
	return (0);
}
