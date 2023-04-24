/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:58 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/24 11:13:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	test(void)
{
	Intern intern;
	std::cout << "*************************************" << std::endl;
	std::cout << "*********** SUCCESS CASES ***********" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat jin("Jin", 1);
		std::cout << "*** testing ShrubberyCreationForm ***" << std::endl;
		AForm*	form1 = intern.makeForm("shrubbery creation" , "here");
		try
		{
			form1->beSigned(jin);
			jin.signForm(*form1);
			jin.executeForm(*form1);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form1;
		std::cout << std::endl;
		std::cout << "*** testing RobotomyRequestForm ***" << std::endl;
		AForm*	form2 = intern.makeForm("robotomy request", jin.getName());
		try
		{
			form2->beSigned(jin);
			jin.signForm(*form2);
			jin.executeForm(*form2);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form2;
		std::cout << std::endl;
		std::cout << "*** testing PresidentialPardonForm ***" << std::endl;
		AForm*	form3 = intern.makeForm("presidential pardon", jin.getName());
		try
		{
			form3->beSigned(jin);
			jin.signForm(*form3);
			jin.executeForm(*form3);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form3;
	}
	catch (const std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		return 1;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "*********** EXCEPTION CASES ***********" << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << "*** testing ShrubberyCreationForm ***" << std::endl;
		AForm*	form1 = intern.makeForm("shrubbery creation" , "here");
		try
		{
			std::cout << "< test 1: form not signed >" << std::endl;
			Bureaucrat jin("Jin", 1);
			std::cout << jin << std::endl;
			std::cout << *form1 << std::endl;
			jin.executeForm(*form1);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form1;
		std::cout << std::endl;
		AForm*	form2 = intern.makeForm("shrubbery creation" , "here");
		try
		{
			std::cout << "< test 2: too low bureaucrat grade >" << std::endl;
			Bureaucrat jin("Jin", 138);
			std::cout << jin << std::endl;
			std::cout << *form2 << std::endl;
			form2->beSigned(jin);
			jin.signForm(*form2);
			jin.executeForm(*form2);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form2;
		std::cout << std::endl;
		std::cout << "*** testing RobotomyRequestForm ***" << std::endl;
		AForm*	form3 = intern.makeForm("robotomy request", "boss");
		try
		{
			std::cout << "< test 1: form not signed >" << std::endl;
			Bureaucrat jin("Jin", 1);
			std::cout << jin << std::endl;
			std::cout << *form3 << std::endl;
			jin.executeForm(*form3);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form3;
		std::cout << std::endl;
		AForm*	form4 = intern.makeForm("robotomy request", "boss");
		try
		{
			std::cout << "< test 2: too low bureaucrat grade >" << std::endl;
			Bureaucrat jin("jin", 60);
			std::cout << jin << std::endl;
			std::cout << *form4 << std::endl;
			form4->beSigned(jin);
			jin.signForm(*form4);
			jin.executeForm(*form4);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form4;
		std::cout << std::endl;
		std::cout << "*** testing PresidentialPardonForm ***" << std::endl;
		AForm*	form5 = intern.makeForm("presidential pardon", "President");
		try
		{
			std::cout << "< test 1: form not signed >" << std::endl;
			Bureaucrat jin("Jin", 1);
			std::cout << jin << std::endl;
			std::cout << *form5 << std::endl;
			jin.executeForm(*form5);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form5;
		std::cout << std::endl;
		AForm*	form6 = intern.makeForm("presidential pardon", "President");
		try
		{
			std::cout << "< test 2: too low bureaucrat grade >" << std::endl;
			Bureaucrat jin("Jin", 10);
			std::cout << jin << std::endl;
			std::cout << *form6 << std::endl;
			form6->beSigned(jin);
			jin.signForm(*form6);
			jin.executeForm(*form6);
		}
		catch (const std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
		delete form6;

		std::cout << "\n*** makeForm() exception ***" << std::endl;
		intern.makeForm("hello", "no");
	}
	catch (const std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught" << ba.what() << std::endl;
		return 1;
	}
	catch (const std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

#include <cstdlib>
int	main(void)
{
	if (test())
		return 1;
	std::system("leaks form");
	return 0;
}
