/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:10:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/25 14:04:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	try
	{
	std::vector<int> test;
	test.push_back(3);
	test.push_back(1);
	test.push_back(6);
	test.push_back(8);
	test.push_back(3);
	test.push_back(9);
	std::cout << "index of value 3: " << easyfind<int>(test, 3) - test.begin() << std::endl;
	std::cout << "non existing value: " << easyfind<int>(test, 100) - test.begin() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
