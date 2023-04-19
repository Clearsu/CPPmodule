/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:50:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 21:57:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", false, SH_SIGNGRADE, SH_EXECGRADE) ,
		_target(NULL) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src.getName(), src.getSigned(), src.getGrade2Sign(), src.getGrade2Execute()), _target(src._target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", false, SH_SIGNGRADE, SH_EXECGRADE),
		_target(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	this->setSigned(src.getSigned());
	this->_target = src._target;
	return *this;
}

bool	ShrubberyCreationForm::execute(const Bureaucrat& execute) const
{
	if (this->getSigned() == false)
		throw ShrubberyCreationForm::ExecuteNotSignedException();
	if (execute.getGrade() > this->getGrade2Execute())
		throw ShrubberyCreationForm::ExecuteGradeLowException();

	std::ofstream of;
	of.open(_target + "_shrubbery", std::ios_base::out);
	if (of.is_open() == false)
		throw ShrubberyCreationForm::OutfileOpenFail();
	of << ASCII_SH << std::endl;
	of.close();
	return true;
}

const char*	ShrubberyCreationForm::ExecuteNotSignedException::what(void) const throw()
{
	return ("exception occurred: ShrubberyCreationForm: it is not signed for execution");
}

const char*	ShrubberyCreationForm::ExecuteGradeLowException::what(void) const throw()
{
	return ("exception occurred: ShrubberyCreationForm: too low bureaucrat grade to execute");
}

const char*	ShrubberyCreationForm::OutfileOpenFail::what(void) const throw()
{
	return ("exception occurred: ShrubberyCreationForm: failed to open a outfile");
}
