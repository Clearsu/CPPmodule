/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:27:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/25 16:21:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConvertor.hpp"

int	main(int argc, char **argv)
{
	// the reason why we use static cast
	/*
	int* ptr = new int[10];
//	char* cptr = static_cast<char*>(ptr);
	char* cptr = (char*)ptr;
	cptr[2147483647123] = 'A';
	*/

	if (argc != 2)
	{
		std::cerr << "error: bad arguments" << std::endl;
		return 1;
	}
	try
	{
		ScalarConvertor::convert(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		return 1;
	}
	return 0;
}
