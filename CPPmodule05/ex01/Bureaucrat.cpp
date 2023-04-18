/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:12 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 11:39:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(NULL), _grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		_grade = src._grade;
	return *this;
}

const std::string&	Bureaucrat::getName(void) const { return _name; }
int					Bureaucrat::getGrade(void) const { return _grade; }

void	Bureaucrat::increaseGrade(void)
{
	if (--_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(void)
{
	if (++_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(const Form& f) const
{
	if (f.getSigned() == true && _grade <= f.getGrade2Sign())
		std::cout << _name << " signed " << f.getName() << std::endl;
	else if (f.getSigned() == true && _grade > f.getGrade2Sign())
		std::cout << _name << " couldn't sign " << f.getName() \
			<< " because his/her grade is lower than the form" << std::endl;
	else if (f.getSigned() == false)
		std::cout << _name << " couldn't sign " << f.getName() \
			<< " because the form hasn't got signed" << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("exception occurred: bureaucrat's grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("exception occurred: bureaucrat's grade too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
