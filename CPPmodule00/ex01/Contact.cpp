/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:08:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/22 13:04:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


//getter
bool	Contact::getState(void) {
	return (state == true);
}

const std::string&	Contact::getFirstName(void) const {
	return (firstName);
}

const std::string&	Contact::getLastName(void) const {
	return (lastName);
}

const std::string&	Contact::getNickName(void) const {
	return (nickName);
}

const std::string&	Contact::getPhoneNumber(void) const {
	return (phoneNumber);
}

const std::string&	Contact::getDarkestSecret(void) const {
	return (darkestSecret);
}


//sether
void	Contact::setState(const bool state) {
	this->state = state;
}

void	Contact::setFirstName(const std::string firstName) {
	this->firstName = firstName;
}

void	Contact::setLastName(const std::string lastName) {
	this->lastName = lastName;
}
void	Contact::setNickName(const std::string nickName) {
	this->nickName = nickName;
}
void	Contact::setPhoneNumber(const std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}
