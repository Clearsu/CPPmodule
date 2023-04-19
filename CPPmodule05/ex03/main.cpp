/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:58 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 17:12:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "*************************************" << std::endl;
	std::cout << "*********** SUCCESS CASES ***********" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "*** testing ShrubberyCreationForm ***" << std::endl;
	try
	{
		Bureaucrat jin("Jin", 1);
		AForm*	form = new ShrubberyCreationForm("here");
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
		AForm*	form = new RobotomyRequestForm(jin.getName());
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
		AForm*	form = new PresidentialPardonForm(jin.getName());
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
		AForm* form = new ShrubberyCreationForm("here");
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
		AForm*	form = new ShrubberyCreationForm("here");
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
		AForm* form = new RobotomyRequestForm("here");
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
		AForm*	form = new RobotomyRequestForm("here");
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
		AForm* form = new PresidentialPardonForm("here");
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
		AForm*	form = new PresidentialPardonForm("here");
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
	return 0;
}
