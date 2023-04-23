/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:54:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/23 16:27:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define LEN 5

template<typename T>
void	increase(T* val)
{
	*val += 1;
}

template<typename T>
void	printElement(T* val)
{
	std::cout << *val << " ";
}

int main(void)
{
	{
		int	a[LEN] = {1, 2, 3, 4, 5};
		::iter<int>(a, LEN, printElement<int>);
		std::cout << std::endl;
		::iter<int>(a, LEN, increase<int>);
		::iter<int>(a, LEN, printElement<int>);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		char a[LEN] = {'a', 'b', 'c', 'd', 'e'};
		::iter<char>(a, LEN, printElement<char>);
		std::cout << std::endl;
		::iter<char>(a, LEN, increase<char>);
		::iter<char>(a, LEN, printElement<char>);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		float a[LEN] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f};
		::iter<float>(a, LEN, printElement<float>);
		std::cout << std::endl;
		::iter<float>(a, LEN, increase<float>);
		::iter<float>(a, LEN, printElement<float>);
		std::cout << std::endl;
	}
    return 0;
}
