/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:50:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 10:59:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(NULL, false, SH_SIGNGRADE, SH_EXECGRADE) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src.getName(), src.getSigned(), src.getGrade2Sign(), src.getGrade2Execute()) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
	: AForm(name, false, SH_SIGNGRADE, SH_EXECGRADE) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	setSigned(src.getSigned());
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& execute) const
{
	if (getSigned() == false || execute.getGrade() > getGrade2Sign())
		throw ShrubberyCreationForm::CanNotExecuteException();
}

const char*	ShrubberyCreationForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: ShrubberyCreationForm: \
			it has not been signed or too low bureaucrat grade");
}
