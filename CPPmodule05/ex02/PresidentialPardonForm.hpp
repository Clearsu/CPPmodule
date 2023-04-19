/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 16:32:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <stdexcept>

# include "AForm.hpp"

# define PR_SIGNGRADE 25
# define PR_EXECGRADE 5

class	PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		bool	execute(const Bureaucrat& execute) const;

		class	ExecuteNotSignedException : public std::exception
		{
			const char*	what(void) const throw();
		};
		class	ExecuteGradeLowException : public std::exception
		{
			const char*	what(void) const throw();
		};
};

#endif
