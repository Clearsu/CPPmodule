/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:57:32 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/17 17:27:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "Cat.hpp"
#include "Dog.hpp"

void	test(void)
{
	std::cout << "*** testing as an array of animals ***" << std::endl;
	Animal	*animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Cat();
	for (int j = 2; j < 4; j++)
		animals[j] = new Dog();
	for (int k = 0; k < 4; k++)
		animals[k]->makeSound();
	for (int l = 0; l < 4; l++)
		delete animals[l];
	std::cout << std::endl;

	std::cout << "*** testing Cat ***" << std::endl;
	Cat	*cat1 = new Cat();
	Cat	*cat2 = new Cat("I'm not a cat");
	std::cout << "cat1's idea: " << cat1->getBrain().getIdea() << std::endl;
	std::cout << "cat2's idea: " << cat2->getBrain().getIdea() << std::endl;
	*cat1 = *cat2;
	std::cout << "cat1's idea: " << cat1->getBrain().getIdea() << std::endl;
	std::cout << "cat2's idea: " << cat2->getBrain().getIdea() << std::endl;
	delete cat1;
	delete cat2;
	std::cout << std::endl;

	std::cout << "*** testing Dog ***" << std::endl;
	Dog	*dog1 = new Dog();
	Dog	*dog2 = new Dog("I'm not a dat");
	std::cout << "Dog1's idea: " << dog1->getBrain().getIdea() << std::endl;
	std::cout << "Dog2's idea: " << dog2->getBrain().getIdea() << std::endl;
	*dog1 = *dog2;
	std::cout << "Dog1's idea: " << dog1->getBrain().getIdea() << std::endl;
	std::cout << "Dog2's idea: " << dog2->getBrain().getIdea() << std::endl;
	delete dog1;
	delete dog2;
}

int	main(void)
{
	test();	
	system("leaks animal");
	return 0;
}
