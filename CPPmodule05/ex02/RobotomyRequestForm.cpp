/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:48:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 12:31:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(NULL, false, RO_SIGNGRADE, RO_EXECGRADE) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src.getName(), src.getSigned(), src.getGrade2Sign(), src.getGrade2Execute()) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string name)
	: AForm(name, false, RO_SIGNGRADE, RO_EXECGRADE) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	setSigned(src.getSigned());
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& execute) const
{
	if (getSigned() == false)
		throw RobotomyRequestForm::ExecuteNotSignedException();
	if (execute.getGrade() > getGrade2Execute())
		throw RobotomyRequestForm::ExecuteGradeLowException();
}

const char*	RobotomyRequestForm::ExecuteNotSignedException::what(void) const throw()
{
	return ("exception occurred: RobotomyRequestForm: it is not signed for execution");
}

const char*	RobotomyRequestForm::ExecuteGradeLowException::what(void) const throw()
{
	return ("exception occurred: RobotomyRequestForm: too low bureaucrat grade to execute");
}
