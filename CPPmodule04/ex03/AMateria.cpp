/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:31:00 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/14 03:08:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria() : _type(NULL)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & a) : _type(a._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria string constructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & a)
{
	if (this != &a)
	{
		this->~AMateria();
		new (this) AMateria(a);
	}
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType(void) const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
}
