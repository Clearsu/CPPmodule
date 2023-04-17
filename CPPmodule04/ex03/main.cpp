/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:39:43 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/17 17:36:50 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

void	test(void)
{
	std::cout << "*** testing actions ***" << std::endl;
	{
		Floor floor;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		floor.setDropped(tmp);
		me->unequip(2);
		me->equip(floor.unsetDropped(0));

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	std::cout << "*** testing deep copy ***" << std::endl;
	{
		Floor floor;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		Character* sam = new Character("sam");
		*sam = *me;
		Character* bob = new Character("bob");
		std::cout << "// my actions" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob);
		me->use(5, *bob);
		std::cout << "// bob's actions" << std::endl;
		tmp = src->createMateria("ice");
		sam->equip(tmp);
		sam->use(0, *bob);
		sam->use(1, *bob);
		sam->use(2, *bob);
		sam->use(3, *bob);
		sam->use(4, *bob);
		sam->use(5, *bob);

		delete bob;
		delete me;
		delete sam;
		delete src;
	}
}

int	main(void)
{
	test();
	system("leaks Materia");
	return 0;
}
