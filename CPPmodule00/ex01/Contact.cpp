/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:08:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/20 04:43:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


//getter
bool	Contact::getState(void) {
	return (state == true);
}

const std::string Contact::getFirstName(void) {
	return (firstName);
}

const std::string Contact::getLastName(void) {
	return (lastName);
}

const std::string Contact::getNickName(void) {
	return (nickName);
}

const std::string Contact::getPhoneNumber(void) {
	return (phoneNumber);
}

const std::string Contact::getDarkestSecret(void) {
	return (darkestSecret);
}


//sether
void	Contact::setState(bool newState) {
	state = newState;
}

void	Contact::setFirstName(const std::string newFirstName) {
	firstName = newFirstName;
}

void	Contact::setLastName(const std::string newLastName) {
	lastName = newLastName;
}
void	Contact::setNickName(const std::string newNickName) {
	nickName = newNickName;
}
void	Contact::setPhoneNumber(const std::string newPhoneNumber) {
	phoneNumber = newPhoneNumber;
}

void	Contact::setDarkestSecret(const std::string newDarkestSecret) {
	darkestSecret = newDarkestSecret;
}
