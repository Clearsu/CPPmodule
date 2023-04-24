/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:27:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/24 10:14:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConvertor.hpp"

int	main(int argc, char **argv)
{
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
