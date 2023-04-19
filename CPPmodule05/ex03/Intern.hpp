/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:15:07 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 21:06:23 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <stdexcept>

class	AForm;

class	Intern
{
	private :
		static const std::string	_nameArray[3];
		static AForm*	(Intern::*func[3])(const std::string &) const;
	public :
		Intern();
		~Intern();

		AForm*	newShrubberyCreationForm(const std::string& target) const;
		AForm*	newRobotomyRequestForm(const std::string& target) const;
		AForm*	newPresidentialPardonForm(const std::string& target) const;

		AForm*	makeForm(const std::string& name, const std::string& target);

		class	FormNotExistException : public std::exception
		{
			const char*	what(void) const throw();
		};
};

#endif
