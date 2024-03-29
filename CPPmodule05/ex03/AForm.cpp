/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:57:23 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 22:03:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>

#include "AForm.hpp"

AForm::AForm() : _name(NULL), _signed(false), _grade2sign(150), _grade2execute(150) {}

AForm::AForm(const AForm& src) : _name(src._name), _signed(src._signed),
								  _grade2sign(src._grade2sign),
									_grade2execute(src._grade2execute) {}

AForm::AForm(const std::string& _name, const int _signed, const int _grade2sign, const int _grade2execute)
	: _name(_name), _signed(_signed), _grade2sign(_grade2sign), _grade2execute(_grade2execute)
{
	if (this->_grade2sign > 150 || this->_grade2execute > 150)
		throw AForm::GradeTooLowException();
	else if (this->_grade2sign < 1 || this->_grade2execute < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

const std::string&	AForm::getName(void) const { return this->_name; }
bool				AForm::getSigned(void) const { return this->_signed; }
int					AForm::getGrade2Sign(void) const { return this->_grade2sign; }
int					AForm::getGrade2Execute(void) const { return this->_grade2execute; }

void	AForm::setSigned(const bool value) { this->_signed = value; }

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_grade2sign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("exception occurred: AForm: grade too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("exception occurred: AForm: grade too low");
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << " " << f.getSigned() << " " << f.getGrade2Sign() << " " << f.getGrade2Execute();
	return os;
}
