/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:26:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 00:49:59 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const & c) : AMateria(c) {}
Cure::~Cure() {}

Cure&	Cure::operator=(Cure const & c)
{
	if (this == &c)
		return *this;
	this->~Cure();
	new (this) Cure(c);
	return *this;
}


AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
