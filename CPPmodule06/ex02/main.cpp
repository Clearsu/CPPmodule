/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:27:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/24 15:26:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	test(void)
{
	try
	{
		Base* random = generate();
		identify(random);
		identify(*random);
		delete random;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		return 1;
	}
	return 0;
}

int	main(void)
{
	if (test())
		return 1;
	std::cout << std::endl;
	std::system("leaks dynamic");
	return 0;
}

