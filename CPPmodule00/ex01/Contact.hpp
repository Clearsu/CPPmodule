/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/20 04:40:54 by jincpark         ###   ########.fr       */
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
		// getter
		bool		getState(void);
		const std::string &getFirstName(void);
		const std::string &getLastName(void);
		const std::string &getNickName(void);
		const std::string &getPhoneNumber(void);
		const std::string &getDarkestSecret(void);
		// setter
		void		setState(bool newState);
		void		setFirstName(const std::string newFirstName);
		void		setLastName(const std::string newLastName);
		void		setNickName(const std::string newNickName);
		void		setPhoneNumber(const std::string newPhoneNumber);
		void		setDarkestSecret(const std::string newDarkestSecret);
};

#endif
