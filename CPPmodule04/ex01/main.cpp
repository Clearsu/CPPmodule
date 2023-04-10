/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:57:32 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 16:59:22 by jincpark         ###   ########.fr       */
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
		const Animal* meta = new Animal();
		meta->makeSound();
		delete meta;

		const Animal* cat = new Cat();
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound(); //will output the cat sound!
		delete cat;

		const Animal* dog = new Dog();
		std::cout << dog->getType() << " " << std::endl;
		dog->makeSound();
		delete dog;
	}
	std::cout << std::endl;
	// no virtualized makeSound() : means no subtype polymorphism
	// everything is determined during compile time
	{
		{
			const	WrongAnimal* meta = new WrongAnimal();
			meta->makeSound();
			delete meta;
			const	WrongAnimal* cat = new WrongCat();
			cat->makeSound(); // the function pointer is pointing the function in the base class
			delete cat;
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
