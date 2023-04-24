/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:12 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/24 09:40:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nobody"), _grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

const std::string&	Bureaucrat::getName(void) const { return this->_name; }
int					Bureaucrat::getGrade(void) const { return this->_grade; }

void	Bureaucrat::increaseGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->_grade + 1> 150)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("error: grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("error: grade too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
