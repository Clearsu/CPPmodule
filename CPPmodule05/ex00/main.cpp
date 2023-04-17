/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:58 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/17 21:34:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "*** case1 : grade too low ***" << std::endl;
	{
		Bureaucrat test("test", 150);
		std::cout << test << std::endl;
		test.decreaseGrade();
		std::cout << test << std::endl;
	}
	std::cout << std::endl;
	std::cout << "*** case2 : grade too high ***" << std::endl;
	{
		Bureaucrat test("test", 1);
		std::cout << test << std::endl;
		test.increaseGrade();
		std::cout << test << std::endl;
	}
	return 0;
}
