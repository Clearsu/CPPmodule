/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:03:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/22 13:12:57 by jincpark         ###   ########.fr       */
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
		Contact 			contact[8];
		int					currentIdx;
		void				increaseIndex(void);
		void				printCategories(void) const;
		void				printAllByIndex(void);
		void				printInformation(int idx) const;
		int					getIdxToPrint(void);	
		const std::string	putDotIfLong(const std::string str);
	public :
		PhoneBook()
		{
			currentIdx = 0;
		}
		void add(void);
		void search(void);
		void printError(int flag) const;
};

#endif
