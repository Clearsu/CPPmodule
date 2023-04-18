/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:41:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 17:40:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::execute(const Bureaucrat& execute) const
{
	if (_signed == false || execute.getGrade() > _grade2sign)
		throw PresidentialPardonForm::CanNotExecuteException();
}

const char*	PresidentialPardonForm::CanNotExecuteException::what(void) const throw()
{
	return ("exception occurred: PresidentialPardonForm: execution not possible");
}
