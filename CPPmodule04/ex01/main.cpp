/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:57:32 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 16:51:04 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// dynamic polymorphism
	// calling overriden method is determined during runtime(dynamic binding)
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	// no virtualized makeSound() : means no dynamic polymorphism
	// everything is determined during compile time
	{
		{
			WrongAnimal* meta = new WrongAnimal();
			meta->makeSound();
			delete meta;
			meta = new WrongCat();
			meta->makeSound(); // the function pointer is still pointing the function in the base class
			delete meta;
		}
		std::cout << std::endl;
		{
			WrongCat* cat = new WrongCat();
			cat->makeSound();
			delete cat;
		}
		std::cout << std::endl;
	}
}
