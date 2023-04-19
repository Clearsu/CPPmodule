/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 11:14:40 by jincpark         ###   ########.fr       */
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
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat& executor) const;
		class	CanNotExecuteException : public std::exception
		{
			const char*	what(void) const throw();
		};
};

#endif
