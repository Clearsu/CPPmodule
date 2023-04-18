/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:58 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 22:34:44 by jincpark         ###   ########.fr       */
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
			ShrubberyCreationForm a("hello");

		}
		catch (std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
	}
	return 0;
}
