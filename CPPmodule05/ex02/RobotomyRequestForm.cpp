/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:48:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 17:41:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void	RobotomyRequestForm::execute(const Bureaucrat& execute) const
{
	if (_signed == false || execute.getGrade() > _grade2sign)
		throw RobotomyRequestForm::CanNotExecuteException();
}

const char*	RobotomyRequestForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: RobotomyRequestForm: execution not possible");
}
