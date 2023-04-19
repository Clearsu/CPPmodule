/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:41:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 10:47:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::execute(const Bureaucrat& execute) const
{
	if (getSigned() == false || execute.getGrade() > getGrade2Sign())
		throw PresidentialPardonForm::CanNotExecuteException();
}

const char*	PresidentialPardonForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: PresidentialPardonForm: execution not possible");
}
