/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/04 20:10:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	dummy;
	Zombie*	horde;
	int		N;

	dummy.setName("dummyZombie");
	N = 5;
	horde = dummy.zombieHorde(N, "WE ARE HORDE!!");
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	delete [] horde;
	return 0;
}
