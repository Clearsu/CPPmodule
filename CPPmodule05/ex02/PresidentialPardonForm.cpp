/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:41:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 11:13:34 by jincpark         ###   ########.fr       */
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
	if (getSigned() == false || execute.getGrade() > getGrade2Sign())
		throw PresidentialPardonForm::CanNotExecuteException();
}

const char*	PresidentialPardonForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: PresidentialPardonForm: \
			it has not been signed or too low bureaucrat grade");
}
