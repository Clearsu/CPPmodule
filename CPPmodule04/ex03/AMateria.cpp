/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:31:00 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 00:49:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(AMateria const & c) : _type(c._type) {}
AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::~AMateria() {}

std::string const & AMateria::getType(void) const { return _type; }

void	AMateria::use(ICharacter& target)
{
	std::cout << "hello " << target.getName() << std::endl;
}
