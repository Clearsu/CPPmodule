/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/22 14:47:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private :
		bool		state;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public :
		Contact()
		{
			state = false;
		}
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
