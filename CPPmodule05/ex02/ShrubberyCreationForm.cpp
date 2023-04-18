/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:50:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 22:48:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(NULL, SH_GRADE, SH_EXEC) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src.getName(), src.getSigned(), src.getGrade2Sign(), src.getGrade2Execute()) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
	: AForm(name, SH_GRADE, SH_EXEC) {}
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	setSigned(src.getSigned());
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& execute) const
{
	if (getSigned() == false || execute.getGrade() > getGrade2Sign())
		throw ShrubberyCreationForm::CanNotExecuteException();
}

const char*	ShrubberyCreationForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: ShrubberyCreationForm: execution not possible");
}
