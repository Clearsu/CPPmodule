/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:08:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/03 18:59:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool	Contact::getState(void) const {
	return _state == true;
}

const std::string&	Contact::getFirstName(void) const {
	return _firstName;
}

const std::string&	Contact::getLastName(void) const {
	return _lastName;
}

const std::string&	Contact::getNickName(void) const {
	return _nickName;
}

const std::string&	Contact::getPhoneNumber(void) const {
	return _phoneNumber;
}

const std::string&	Contact::getDarkestSecret(void) const {
	return _darkestSecret;
}

void	Contact::setState(const bool state) {
	_state = state;
}

void	Contact::setFirstName(const std::string firstName) {
	_firstName = firstName;
}

void	Contact::setLastName(const std::string lastName) {
	_lastName = lastName;
}
void	Contact::setNickName(const std::string nickName) {
	_nickName = nickName;
}
void	Contact::setPhoneNumber(const std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string darkestSecret) {
	_darkestSecret = darkestSecret;
}
