/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:57:32 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 16:32:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// subtype polymorphism
	// calling overriden method is determined at runtime(dynamic binding)
	{
		Animal*	meta = new Animal();
		meta->makeSound();
		meta = new Cat();
		meta->makeSound();
		meta = new Dog();
		meta->makeSound();
		delete meta;
	}
	std::cout << std::endl;
	// no virtualized makeSound() : means no subtype polymorphism
	// everything is determined during compile time
	{
		{
			WrongAnimal* meta = new WrongAnimal();
			meta->makeSound();
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
