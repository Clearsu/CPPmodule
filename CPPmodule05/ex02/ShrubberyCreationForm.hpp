/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:51:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/19 13:23:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <stdexcept>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# define SH_SIGNGRADE 145
# define SH_EXECGRADE 137

# define ASCII_SH "\n\
	                              # #### ####\n\
                                ### \\/#|### |/####\n\
                               ##\\/#/ \\||/##/_/##/_#\n\
                             ###  \\/###|/ \\/ # ###\n\
                           ##_\\_#\\_\\## | #/###_/_####\n\
                          ## #### # \\ #| /  #### ##/##\n\
                           __#_--###`  |{,###---###-~\n\
                                     \\ }{\n\
                                      }}{\n\
                                      }}{\n\
                                      {{}\n\
                                , -=-~{ .-^- _\n\
                                      `}\n\
                                       {\n"

class	ShrubberyCreationForm : public AForm
{
	private :
		std::string	_target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor) const;

		class	ExecuteNotSignedException : public std::exception
		{
			const char*	what(void) const throw();
		};
		class	ExecuteGradeLowException : public std::exception
		{
			const char*	what(void) const throw();
		};
		class	OutfileOpenFail : public std::exception
		{
			const char* what(void) const throw();
		};
};

#endif
