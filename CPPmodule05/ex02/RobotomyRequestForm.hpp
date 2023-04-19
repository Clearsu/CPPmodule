/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:47:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 11:15:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <stdexcept>

# include "AForm.hpp"

# define RO_SIGNGRADE 72
# define RO_EXECGRADE 45

class	RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		void	execute(const Bureaucrat& executor) const;
		class	CanNotExecuteException : public std::exception
		{
			const char*	what(void) const throw();
		};
};

#endif
