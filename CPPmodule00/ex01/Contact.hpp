/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/15 18:18:55 by jincpark         ###   ########.fr       */
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
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
		// setter
		void		setState(bool newState);
		void		setFirstName(const std::string newFirstName);
		void		setLastName(const std::string newLastName);
		void		setNickName(const std::string newNickName);
		void		setPhoneNumber(const std::string newPhoneNumber);
		void		setDarkestSecret(const std::string newDarkestSecret);
};

#endif
