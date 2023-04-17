/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:12 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/17 21:30:00 by jincpark         ###   ########.fr       */
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
	try
	{
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
	try
	{
		if (--_grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decreaseGrade(void)
{
	try
	{
		if (++_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("exception occurred: grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("exception occurred: grade too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
