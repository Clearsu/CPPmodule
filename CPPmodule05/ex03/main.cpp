/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:58 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 21:10:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern;
	std::cout << "*************************************" << std::endl;
	std::cout << "*********** SUCCESS CASES ***********" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "*** testing ShrubberyCreationForm ***" << std::endl;
	try
	{
		AForm*	form = intern.makeForm("shrubbery creation", "here");
		Bureaucrat jin("Jin", 1);
		form->beSigned(jin);
		jin.signForm(*form);
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "*** testing RobotomyRequestForm ***" << std::endl;
	try
	{
		Bureaucrat jin("Jin", 1);
		AForm*	form = intern.makeForm("robotomy request", jin.getName());
		form->beSigned(jin);
		jin.signForm(*form);
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "*** testing PresidentialPardonForm ***" << std::endl;
	try
	{
		Bureaucrat jin("Jin", 1);
		AForm*	form = intern.makeForm("presidential pardon", jin.getName());
		form->beSigned(jin);
		jin.signForm(*form);
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "*********** EXCEPTION CASES ***********" << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "*** testing ShrubberyCreationForm ***" << std::endl;
	try
	{
		std::cout << "< test 1: form not signed >" << std::endl;
		Bureaucrat jin("Jin", 1);
		AForm*	form = intern.makeForm("shrubbery creation", "here");
		std::cout << jin << std::endl;
		std::cout << *form << std::endl;
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "< test 2: too low bureaucrat grade >" << std::endl;
		Bureaucrat jin("Jin", 138);
		AForm*	form = intern.makeForm("shrubbery creation", jin.getName());
		std::cout << jin << std::endl;
		std::cout << *form << std::endl;
		form->beSigned(jin);
		jin.signForm(*form);
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "*** testing RobotomyRequestForm ***" << std::endl;
	try
	{
		std::cout << "< test 1: form not signed >" << std::endl;
		Bureaucrat jin("Jin", 1);
		AForm*	form = intern.makeForm("robotomy request", jin.getName());
		std::cout << jin << std::endl;
		std::cout << *form << std::endl;
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "< test 2: too low bureaucrat grade >" << std::endl;
		Bureaucrat jin("jin", 60);
		AForm*	form = intern.makeForm("robotomy request", jin.getName());
		std::cout << jin << std::endl;
		std::cout << *form << std::endl;
		form->beSigned(jin);
		jin.signForm(*form);
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "*** testing PresidentialPardonForm ***" << std::endl;
	try
	{
		std::cout << "< test 1: form not signed >" << std::endl;
		Bureaucrat jin("Jin", 1);
		AForm*	form = intern.makeForm("presidential pardon", jin.getName());
		std::cout << jin << std::endl;
		std::cout << *form << std::endl;
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "< test 2: too low bureaucrat grade >" << std::endl;
		Bureaucrat jin("Jin", 10);
		AForm*	form = intern.makeForm("presidential pardon", jin.getName());
		std::cout << jin << std::endl;
		std::cout << *form << std::endl;
		form->beSigned(jin);
		jin.signForm(*form);
		jin.executeForm(*form);
		delete form;
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "*** testing PresidentialPardonForm ***" << std::endl;
	try
	{
		intern.makeForm("form not exist", "hello");
	}
	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	return 0;
}
