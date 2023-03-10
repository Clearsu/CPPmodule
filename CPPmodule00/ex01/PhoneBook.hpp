/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:03:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/13 22:58:09 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define INVALID_COMMAND 0
# define INVALID_INDEX 1

class PhoneBook
{
	private :
		Contact contact[8];
		int		i;

		void increaseIndex(void);
	public :
		PhoneBook()
		{
			i = 0;
		}
		void add(void);
		void search(void);
		void exitPhoneBook(void);
		void printError(int flag);
};

#endif
