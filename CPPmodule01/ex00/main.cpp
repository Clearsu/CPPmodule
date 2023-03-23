/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/23 20:22:18 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Zombie.hpp"

void	checkLeaks(void) {
	system("leaks --list zombie");
}

int	main(void) {
	Zombie	a;
	Zombie*	b;

	a.setName("zombieA");
	a.announce();
	b = a.newZombie("newZombie");
	b->announce();
	delete b;
	a.randomChump("randomZombie");
	atexit(checkLeaks);
	return 0;
}
