/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:03:53 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/11 16:35:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	executePhoneBook(void)
{
	PhoneBook	phonebook;
	std::string	str;

	while (TRUE)
	{
		std::getline(std::cin, str);
		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		else if (str == "EXIT")
			phonebook.exitProgram();
		else
			displayErrorMessage();
	}
}

int	main(void)
{
	PhoneBook phonebook;
}
