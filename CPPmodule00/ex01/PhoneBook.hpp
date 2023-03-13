/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:03:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/13 15:09:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

void	addFirstName(std::string str)
{
	std::cout << "first name: ";
	std::getline(std::cin, str);
}

void	addLastName(std::string str)
{
	std::cout << "last name: ";
	std::getline(std::cin, str);
}

void	addNickName(std::string str)
{
	std::cout << "nickname: ";
	std::getline(std::cin, str);
}

void	addPhoneNumber(std::string str)
{
	std::cout << "phone number: ";
	std::getline(std::cin, str);
}

void	addDarkestSecret(std::string str)
{
	std::cout << "darkest secret: ";
	std::getline(std::cin, str);
}

class PhoneBook
{
	public :
		void addFirstName(std::string str);
		void addLastName(std::string str);
		void addNickName(std::string str);
		void addPhoneNumber(std::string str);
		void addDarkestSecret(std::string str);
};

#endif
