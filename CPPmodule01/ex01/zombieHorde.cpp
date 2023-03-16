/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:02:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 18:25:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int N, std::string name) {
	Zombie	*ret;

	ret = new Zombie[N];
	for (int i = 0; i < N; ++i)
		ret[i].setName(name);
	return (ret);
}
