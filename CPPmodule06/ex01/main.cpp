/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:48:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/25 10:08:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>

#include "Serializer.hpp"

#define W 30

int	test(void)
{
	try
	{
		Data* ptr = new Data;
		uintptr_t s_ptr = Serializer::serialize(ptr);
		unsigned long ul_ptr = reinterpret_cast<unsigned long>(ptr);
		Data* ds_ptr = Serializer::deserialize(s_ptr);
		Data* origin_ptr = reinterpret_cast<Data*>(ul_ptr);

		std::cout << std::setw(W) << "ptr: ";
		std::cout << ptr << std::endl;

		std::cout << std::setw(W) << "serialized ptr: ";
		std::cout << s_ptr << std::endl;

		std::cout << std::setw(W) << "deserialized ptr: ";
		std::cout << ds_ptr << std::endl;

		std::cout << std::setw(W) << "ptr casted to unsigned long: ";
		std::cout << ul_ptr << std::endl;

		std::cout << std::setw(W) << "ptr casted back to Data*: ";
		std::cout << origin_ptr << std::endl;

//		unsigned long test = static_cast<unsigned long>(ptr);
		delete ptr;
	}
	catch (const std::bad_alloc& ba)
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
	std::system("leaks serialize");
	return 0;
}
