/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:51:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 17:39:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <stdexcept>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# define SH_GRADE 145
# define SH_EXEC 137

class	ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm(const std::string name);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor) const;
		class	CanNotExecuteException : public std::exception
		{
			const char*	what(void) const throw();
		};
}

#endif
