/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:50:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 17:41:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(NULL, SH_GRADE, SH_EXEC) {}
ShrubberyCreationForm::ShrebberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src._name, src._signed, src._grade2sign, src._grade2execute) {}
ShrubberyCreationForm::ShrebberyCreationForm(const std::string name)
	: AForm(name, SH_GRADE, SH_EXEC) {}
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	setSigned(src.getSigned());
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& execute) const
{
	if (_signed == false || execute.getGrade() > _grade2sign)
		throw ShrubberyCreationForm::CanNotExecuteException();
}

const char*	ShrubberyCreationForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: ShrubberyCreationForm: execution not possible");
}
