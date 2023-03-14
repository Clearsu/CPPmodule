/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:09:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/14 22:58:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

void	PhoneBook::add(void) {
	std::string tmp;
	Contact		&currentContact = contact[currentIdx];

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
	int	idxToPrint;

	printCategories();
	printAllByIndex();
	idxToPrint = getIdxToPrint();
	if (idxToPrint == -1)
		return ;
	printInformation(idxToPrint);
}

void	PhoneBook::exitPhoneBook(void) {
	exit(0);
}

void	PhoneBook::printError(int flag)
{
	if (flag == INVALID_COMMAND)
		std::cout << "phonebook: invalid command\n";
	else if (flag == INDEX_OUT_OF_RANGE)
		std::cout << "phonebook: index out of range\n";
}

void	PhoneBook::increaseIndex(void) {
	if (currentIdx < 7)
		++currentIdx;
	else
		currentIdx = 0;
}

void	PhoneBook::printCategories(void) {
	std::cout << std::endl;
	std::cout << std::setw(10);
	std::cout << "INDEX" << "|";
	std::cout << std::setw(10);
	std::cout << "FIRST NAME" << "|";
	std::cout << std::setw(10);
	std::cout << "LAST NAME" << "|";
	std::cout << std::setw(10);
	std::cout << "NICKNAME";
	std::cout << std::endl;
}

void	PhoneBook::printAllByIndex(void) {
	for (int i = 0; i < 8; ++i) {
		if (contact[i].getState() == true) {
			std::cout << std::setw(10);
			std::cout << i << "|";
			std::cout << std::setw(10);
			std::cout << contact[i].getFirstName() << "|";
			std::cout << std::setw(10);
			std::cout << contact[i].getLastName() << "|";
			std::cout << std::setw(10);
			std::cout << contact[i].getNickName();
			std::cout << "\n";
		}
	}
}

void	PhoneBook::printInformation(int idxToPrint) {
	std::cout << "\nFirst name: " << contact[idxToPrint].getFirstName() << "\n";
	std::cout << "Last name: " << contact[idxToPrint].getLastName() << "\n";
	std::cout << "Nickname: " << contact[idxToPrint].getNickName() << "\n";
	std::cout << "Phone number: " << contact[idxToPrint].getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contact[idxToPrint].getDarkestSecret() << "\n\n";
}

int	PhoneBook::getIdxToPrint(void) {
	std::string idxString;
	int			idxToPrint;

	std::cout << std::endl << "type an index you want > ";
	std::getline(std::cin, idxString);
	std::stringstream ssInt(idxString);
	ssInt >> idxToPrint;
	if (idxToPrint < 0 || idxToPrint > 7 || contact[idxToPrint].getState() == false) {
		printError(INDEX_OUT_OF_RANGE);
		return (-1);
	}
	return (idxToPrint);
}