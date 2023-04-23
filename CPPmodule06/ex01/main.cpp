/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:48:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/23 14:11:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int	main(void)
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
	std::cout << "ptr casted back to original type: " << origin_ptr << std::endl;
	delete ptr;
}
