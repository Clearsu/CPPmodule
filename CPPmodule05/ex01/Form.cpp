/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:57:23 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 11:41:23 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>

#include "Form.hpp"

Form::Form() : _name(NULL), _signed(false), _grade2sign(100), _grade2execute(100) {}
Form::Form(const Form& src) : _name(src._name), _signed(src._signed),
								  _grade2sign(src._grade2sign),
									_grade2execute(src._grade2execute) {}
Form::Form(const std::string& name, const int grade2sign,
		const int grade2execute) : _name(name), _signed(false), _grade2sign(grade2sign),
									_grade2execute(grade2execute)
{
	if (_grade2sign > 150 || _grade2execute > 150)
		throw Form::GradeTooLowException();
	else if (_grade2sign < 1 || _grade2execute < 1)
		throw Form::GradeTooHighException();
}
Form::~Form() {}

Form&	Form::operator=(const Form& src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

const std::string&	Form::getName(void) const { return _name; }
bool				Form::getSigned(void) const { return _signed; }
int					Form::getGrade2Sign(void) const { return _grade2sign; }
int					Form::getGrade2Execute(void) const { return _grade2execute; }

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _grade2sign)
		_signed = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("exception occurred: form's grade too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("exception occurred: form's grade too low");
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << " " << f.getSigned() << " " << f.getGrade2Sign() << " " << f.getGrade2Execute();
	return os;
}
