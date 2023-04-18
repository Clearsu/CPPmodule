/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:47:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 22:50:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <stdexcept>

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public :
		void	execute(const Bureaucrat& executor) const;
		class	CanNotExecuteException : public std::exception
		{
			const char*	what(void) const throw();
		};
};

#endif
