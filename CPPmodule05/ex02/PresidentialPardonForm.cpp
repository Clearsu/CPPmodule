/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:41:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 12:29:36 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(NULL, false, PR_SIGNGRADE, PR_EXECGRADE) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src.getName(), src.getSigned(), src.getGrade2Sign(), src.getGrade2Execute()) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string name)
	: AForm(name, false, PR_SIGNGRADE, PR_EXECGRADE) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	setSigned(src.getSigned());
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& execute) const
{
	if (getSigned() == false)
		throw PresidentialPardonForm::ExecuteNotSignedException();
	if (execute.getGrade() > getGrade2Execute())
		throw PresidentialPardonForm::ExecuteGradeLowException();
}

const char*	PresidentialPardonForm::ExecuteNotSignedException::what(void) const throw()
{
	return ("exception occurred: PresidentialPardonForm: it is not signed for execution");
}

const char*	PresidentialPardonForm::ExecuteGradeLowException::what(void) const throw()
{
	return ("exception occurred: PresidentialPardonForm: too low bureaucrat grade to execute");
}
