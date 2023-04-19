/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:48:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 16:30:49 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", false, RO_SIGNGRADE, RO_EXECGRADE) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src.getName(), src.getSigned(), src.getGrade2Sign(), src.getGrade2Execute()), _target(src._target) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", false, RO_SIGNGRADE, RO_EXECGRADE),
		_target(target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	setSigned(src.getSigned());
	_target = src._target;
	return *this;
}

bool	RobotomyRequestForm::execute(const Bureaucrat& execute) const
{
	if (getSigned() == false)
		throw RobotomyRequestForm::ExecuteNotSignedException();
	if (execute.getGrade() > getGrade2Execute())
		throw RobotomyRequestForm::ExecuteGradeLowException();
	std::srand(time(NULL));
	if ((std::rand() & 1) == true)
	{
		std::cout << _target << " has been robotomized successfully" << std::endl;
		return true;
	}
	std::cout << "robotomization against " << _target << " failed" << std::endl;
	return false;
}

const char*	RobotomyRequestForm::ExecuteNotSignedException::what(void) const throw()
{
	return ("exception occurred: RobotomyRequestForm: it is not signed for execution");
}

const char*	RobotomyRequestForm::ExecuteGradeLowException::what(void) const throw()
{
	return ("exception occurred: RobotomyRequestForm: too low bureaucrat grade to execute");
}
