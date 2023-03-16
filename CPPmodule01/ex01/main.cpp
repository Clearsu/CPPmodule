/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 18:45:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Zombie.hpp"

void	checkLeak(void)
{
	system("leaks --list zombie");
}

int	main(void)
{
	Zombie	dummy;
	Zombie*	horde;
	int		N;

	dummy.setName("dummyZombie");
	N = 5;
	horde = dummy.zombieHorde(N, "WE ARE HORDE!!");
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	delete [] horde;
	atexit(checkLeak);
	return (0);
}
