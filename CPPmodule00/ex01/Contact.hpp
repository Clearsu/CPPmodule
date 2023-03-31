/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/31 20:58:18 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private :
		bool		_state;
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public :
		Contact() : _state(false) {}
		bool				getState(void) const;
		const std::string	&getFirstName(void) const;
		const std::string	&getLastName(void) const;
		const std::string	&getNickName(void) const;
		const std::string	&getPhoneNumber(void) const;
		const std::string	&getDarkestSecret(void) const;
		void				setState(const bool state);
		void				setFirstName(const std::string firstName);
		void				setLastName(const std::string lastName);
		void				setNickName(const std::string nickName);
		void				setPhoneNumber(const std::string phoneNumber);
		void				setDarkestSecret(const std::string darkestSecret);
};

#endif
