/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 17:59:09 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	a;
	Zombie	dummy;

	dummy.setName("dummyZombie");
	dummy.announce();
	a = dummy.newZombie("zombieA");
	delete a;
	dummy.randomChump("zombieB");
}
