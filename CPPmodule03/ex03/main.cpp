/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:40:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 22:12:13 by jincpark         ###   ########.fr       */
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
	return 0;
}
