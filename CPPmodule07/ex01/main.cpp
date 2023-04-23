/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:54:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/23 17:31:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define LEN 5

template<typename T>
void	printElement(const T& val)
{
	std::cout << "value: " << val << std::endl;
}

int main(void)
{
	{
		int	a[LEN] = {1, 2, 3, 4, 5};
		::iter<int>(a, LEN, printElement<int>);
	}
	std::cout << std::endl;
	{
		char a[LEN] = {'a', 'b', 'c', 'd', 'e'};
		::iter<char>(a, LEN, printElement<char>);
	}
	std::cout << std::endl;
	{
		float a[LEN] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f};
		::iter<float>(a, LEN, printElement<float>);
	}
    return 0;
}
