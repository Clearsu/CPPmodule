/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:48:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 22:50:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

void	RobotomyRequestForm::execute(const Bureaucrat& execute) const
{
	if (getSigned() == false || execute.getGrade() > getGrade2Sign())
		throw RobotomyRequestForm::CanNotExecuteException();
}

const char*	RobotomyRequestForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: RobotomyRequestForm: execution not possible");
}
