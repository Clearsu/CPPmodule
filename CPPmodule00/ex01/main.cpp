/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:10:36 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/13 22:57:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	while (1) {
		std::cout << "type a command > ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			phonebook.exitPhoneBook();
		else
			phonebook.printError(INVALID_COMMAND);
	}
}
