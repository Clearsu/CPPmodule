/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:10:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 15:22:40 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int main(void)
{
	std::vector<char> test1;

	test1.push_back(3);
	test1.push_back(1);
	test1.push_back(6);
	test1.push_back(8);
	test1.push_back(3);
	test1.push_back(9);

	std::cout << easyfind(test1, 8) << std::endl;
	std::cout << easyfind(test1, 10) << std::endl;

	std::list<double> test2;

	test2.push_back(3);
	test2.push_back(1);
	test2.push_back(6);
	test2.push_back(8);
	test2.push_back(3);
	test2.push_back(9);

	std::cout << easyfind(test2, 8) << std::endl;
	std::cout << easyfind(test2, 10) << std::endl;

	std::deque<float> test3;

	test3.push_back(3);
	test3.push_back(1);
	test3.push_back(6);
	test3.push_back(8);
	test3.push_back(3);
	test3.push_back(9);

	std::cout << easyfind(test3, 8) << std::endl;
	std::cout << easyfind(test3, 10) << std::endl;

	return 0;
}
