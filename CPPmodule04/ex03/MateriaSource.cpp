/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:37:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 00:43:52 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _ice(NULL), _cure(NULL) {}

MateriaSource::MateriaSource(MateriaSource const & c) : _ice(NULL), _cure(NULL)
{
	if (c._ice != NULL)
		_ice = new Ice();
	if (c._cure != NULL)
		_cure = new Cure();
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & c)
{
	if (this == &c)
		return *this;
	this->~MateriaSource();
	new (this) MateriaSource(c);
	return *this;
}

MateriaSource::~MateriaSource()
{
	if (_ice != NULL)
		delete _ice;
	if (_cure != NULL)
		delete _cure;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m->getType() == "ice")
		_ice = (Ice *)m;
	else if (m->getType() == "cure")
		_cure = (Cure *)m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice" && _ice != NULL)
		return _ice->clone();
	if (type == "cure" && _cure != NULL)
		return _cure->clone();
	std::cout << "No such Materia type: " << type << std::endl;
	return NULL;
}
