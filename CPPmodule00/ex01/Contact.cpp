/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:08:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/13 22:05:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool	Contact::getState(void) {
	return (state == true);
}

std::string Contact::getFirstName(void) {
	return (firstName);
}

std::string Contact::getLastName(void) {
	return (lastName);
}

std::string Contact::getNickName(void) {
	return (nickName);
}

std::string Contact::getPhoneNumber(void) {
	return (phoneNumber);
}

std::string Contact::getDarkestSecret(void) {
	return (darkestSecret);
}

void	Contact::setState(bool newState) {
	state = newState;
}

void	Contact::setFirstName(std::string newFirstName) {
	firstName = newFirstName;
}

void	Contact::setLastName(std::string newLastName) {
	lastName = newLastName;
}
void	Contact::setNickName(std::string newNickName) {
	nickName = newNickName;
}
void	Contact::setPhoneNumber(std::string newPhoneNumber) {
	phoneNumber = newPhoneNumber;
}

void	Contact::setDarkestSecret(std::string newDarkestSecret) {
	darkestSecret = newDarkestSecret;
}
