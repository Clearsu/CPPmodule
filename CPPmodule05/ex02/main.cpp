/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:58 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 13:31:40 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	{
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
	}
	return 0;
}
