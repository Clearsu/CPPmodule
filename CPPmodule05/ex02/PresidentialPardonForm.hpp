/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 10:48:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <stdexcept>

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public :
		void	execute(const Bureaucrat& executor) const;
		class	CanNotExecuteException : public std::exception
		{
			const char*	what(void) const throw();
		};
};

#endif
