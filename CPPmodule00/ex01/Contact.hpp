/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/13 15:09:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	public :
		int			isFilled;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	private :
		Contact()
		{
			isFilled = FALSE;
			firstName = 0;
			lastName = 0;
			nickName = 0;
			phoneNumber = 0;
			darkestSecret = 0;
		}
};

#endif
