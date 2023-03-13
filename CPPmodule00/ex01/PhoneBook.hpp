/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:03:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/11 16:36:52 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

# define FALSE 0
# define TRUE 1
# define MAX 8

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

class PhoneBook
{
	private :
		int		i;
		Contact contact[MAX];
		PhoneBook()
		{
			i = 0;
		}
		~PhoneBook()
		{
		}
		void	modifyContactIndex(Contact contact[MAX], int *i)
		{
			if (contact[*i].isFilled == TRUE && *i < MAX - 1)
			{
				*i += 1;
				return ;
			}
			if (contact[*i].isFilled = FALSE)
				return ;
			if (*i == MAX - 1)
			{
				*i = 0;
				return ;
			}
		}
	public :
		void add(void)
		{
			modifyContactIndex(contact, &i);
			std::cout << "first name: ";
			std::getline(std::cin, contact[i].firstName);
			std::cout << "last name: ";
			std::getline(std::cin, contact[i].lastName);
			std::cout << "nickname: ";
			std::getline(std::cin, contact[i].nickName);
			std::cout << "phone number: ";
			std::getline(std::cin, contact[i].phoneNumber);
			std::cout << "darkest secret: ";
			std::getline(std::cin, contact[i].darkestSecret);
		}
		void search(void)
		{
		}
		void exitProgram(void)
		{
			exit(0);
		}
};

#endif
