/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:15:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/17 14:34:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const & c) : AMateria(c) {}
Ice::~Ice() {}

Ice&	Ice::operator=(Ice const & c)
{
	if (this == &c)
		return *this;
	this->~Ice();
	new (this) Ice(c);
	return *this;
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
