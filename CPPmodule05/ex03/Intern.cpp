/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:21:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 22:05:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}

const std::string	Intern::_nameArray[3] = {
	"shrubbery creation", 
	"robotomy request", 
	"presidential pardon"
};

AForm*	(Intern::*Intern::func[3])(const std::string &) const = {
	&Intern::newShrubberyCreationForm,
	&Intern::newRobotomyRequestForm,
	&Intern::newPresidentialPardonForm
};

AForm*	Intern::newShrubberyCreationForm(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}
AForm*	Intern::newRobotomyRequestForm(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}
AForm*	Intern::newPresidentialPardonForm(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm*	ret = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (name == this->_nameArray[i])
			ret = (this->*func[i])(target);
	}
	if (!ret)
		throw Intern::FormNotExistException();
	return ret;
}

const char*	Intern::FormNotExistException::what(void) const throw()
{
	return ("exception occurred: Intern: no such form");
}
