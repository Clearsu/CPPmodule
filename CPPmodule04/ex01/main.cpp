/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:57:32 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 22:29:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

#include <stdlib.h>
int	main(void)
{
	{
		// original animals
		Animal*	animals[10];
		for (int i = 0; i < 5; i++)
		{
			animals[i] = new Cat();
			animals[i]->setBrain("I want a fish");
		}
		for (int j = 5; j < 10; j++)
		{
			animals[j] = new Dog();
			animals[j]->setBrain("I want a bone");
		}

		// copy animals and change original animal's brain
		Animal animals_copy[10];
		for (int l = 0; l < 10; l++)
		{
			animals_copy[l] = *animals[l];
			animals[l]->setBrain("I am sleepy");
		}
		for (int m = 0; m < 10; m++)
			std::cout << animals_copy[m].getBrainPtr()->getIdea(0) << std::endl;
		for (int k = 0; k < 10; k++)
			delete animals[k];
	}
	system("leaks animal");
}
