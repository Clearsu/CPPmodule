/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:41:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 21:53:23 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", false, PR_SIGNGRADE, PR_EXECGRADE), _target(NULL) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src.getName(), src.getSigned(), src.getGrade2Sign(), src.getGrade2Execute()), _target(src._target) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", false, PR_SIGNGRADE, PR_EXECGRADE), _target(target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	setSigned(src.getSigned());
	this->_target = src._target;
	return *this;
}

bool	PresidentialPardonForm::execute(const Bureaucrat& execute) const
{
	if (this->getSigned() == false)
		throw PresidentialPardonForm::ExecuteNotSignedException();
	if (execute.getGrade() > this->getGrade2Execute())
		throw PresidentialPardonForm::ExecuteGradeLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return true;
}

const char*	PresidentialPardonForm::ExecuteNotSignedException::what(void) const throw()
{
	return ("exception occurred: PresidentialPardonForm: it is not signed for execution");
}

const char*	PresidentialPardonForm::ExecuteGradeLowException::what(void) const throw()
{
	return ("exception occurred: PresidentialPardonForm: too low bureaucrat grade to execute");
}
