/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:03:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/15 18:18:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

// error flag
# define INVALID_COMMAND 0
# define INDEX_OUT_OF_RANGE 1

class PhoneBook
{
	private :
		Contact 	contact[8];
		int			currentIdx;
		void		increaseIndex(void);
		void		printCategories(void);
		void		printAllByIndex(void);
		void		printInformation(int idx);
		int			getIdxToPrint(void);	
		std::string	putDotIfLong(std::string str);
	public :
		PhoneBook()
		{
			currentIdx = 0;
		}
		void add(void);
		void search(void);
		void exitPhoneBook(void);
		void printError(int flag);
};

#endif
