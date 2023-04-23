/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:28:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/23 15:20:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	val;

	std::srand(time(NULL));
	val = std::rand() % 3;
	switch (val)
	{
		case 0 :
			return new A;
		case 1 :
			return new B;
		case 2 :
			return new C;
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "it is an instance of class A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "it is an instance of class B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "it is an instance of class C" << std::endl;
}

void	identify(Base& p)
{
	int	eflag = 0;

	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
	}
	catch (std::bad_cast& bc)
	{
		eflag = eflag | 0b001;
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
	}
	catch (std::bad_cast& bc)
	{
		eflag = eflag | 0b010;
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
	}
	catch (std::bad_cast& bc)
	{
		eflag = eflag | 0b100;
	}

	switch (eflag ^ 0b111)
	{
		case 0b001 :
			std::cout << "it is an instance of class A" << std::endl;
			break ;
		case 0b010 :
			std::cout << "it is an instance of class B" << std::endl;
			break ;
		case 0b100 :
			std::cout << "it is an instance of class C" << std::endl;
	}
}
