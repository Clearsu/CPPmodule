/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:09:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/13 22:59:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

void	PhoneBook::increaseIndex(void) {
	if (i < 7)
		++i;
	else
		i = 0;
}

void	PhoneBook::add(void) {
	std::string tmp;
	Contact		&currentContact = contact[i];

	std::cout << "first name: ";
	std::getline(std::cin, tmp);
	currentContact.setFirstName(tmp);
	std::cout << "last name: ";
	std::getline(std::cin, tmp);
	currentContact.setLastName(tmp);
	std::cout << "nickname: ";
	std::getline(std::cin, tmp);
	currentContact.setNickName(tmp);
	std::cout << "phone number: ";
	std::getline(std::cin, tmp);
	currentContact.setPhoneNumber(tmp);
	std::cout << "darkest secret: ";
	std::getline(std::cin, tmp);
	currentContact.setDarkestSecret(tmp);
	currentContact.setState(true);
	increaseIndex();
}

void	PhoneBook::search(void) {
	std::string idxString;
	int			idx;

	for (int i = 0; i < 8; ++i) {
		if (contact[i].getState() == true) {
			std::cout << std::setw(11);
			std::cout << i << "|";
			std::cout << std::setw(11);
			std::cout << contact[i].getFirstName() << "|";
			std::cout << std::setw(11);
			std::cout << contact[i].getLastName() << "|";
			std::cout << std::setw(11);
			std::cout << contact[i].getNickName() << "\n";
		}
	}
	std::cout << "type an index you want > ";
	std::getline(std::cin, idxString);
	std::stringstream ssInt(idxString);
	ssInt >> idx;
	if (idx < 0 || idx > 7) {
		printError(INVALID_INDEX);
		return ;
	}
}

void	PhoneBook::exitPhoneBook(void) {
	exit(0);
}

void	PhoneBook::printError(int flag)
{
	if (flag == INVALID_COMMAND)
		std::cout << "phonebook: invalid command\n";
	else if (flag == INVALID_INDEX)
		std::cout << "phonebook: index out of range\n";
}
