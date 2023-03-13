/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/13 22:04:18 by jincpark         ###   ########.fr       */
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
		bool		getState(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
		void		setState(bool newState);
		void		setFirstName(std::string newFirstName);
		void		setLastName(std::string newLastName);
		void		setNickName(std::string newNickName);
		void		setPhoneNumber(std::string newPhoneNumber);
		void		setDarkestSecret(std::string newDarkestSecret);
};

#endif
