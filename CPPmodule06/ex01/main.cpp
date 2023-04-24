/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:48:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/24 15:17:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "Serializer.hpp"

int	test(void)
{
	try
	{
		Data* ptr = new Data;
		std::cout << "ptr: " << ptr << std::endl;
		uintptr_t s_ptr = Serializer::serialize(ptr);
		std::cout << "serialized ptr: " << s_ptr << std::endl;
		Data* ds_ptr = Serializer::deserialize(s_ptr);
		std::cout << "deserialized ptr: " << ds_ptr << std::endl;
		unsigned long ul_ptr = reinterpret_cast<unsigned long>(ptr);
		std::cout << "ptr casted to unsigned long: " << ul_ptr << std::endl;
		Data* origin_ptr = reinterpret_cast<Data*>(ul_ptr);
		std::cout << "ptr casted back to Data*: " << origin_ptr << std::endl;
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
