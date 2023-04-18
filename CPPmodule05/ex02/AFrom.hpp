/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:44:20 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/18 11:46:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdexcept>
# include <ostream>

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_grade2sign;
		const int			_grade2execute;
	public :
		Form();
		Form(const Form& src);
		Form(const std::string& _name, const int _grade2sign, const int _grade2execute);
		Form&	operator=(const Form& src);
		~Form();

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getGrade2Sign(void) const;
		int					getGrade2Execute(void) const;

		void	beSigned(const Bureaucrat& b);

		class	GradeTooHighException : public std::exception
		{
			public :
				const char*	what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				const char*	what(void) const throw();
		};
};

std::ostream&	 operator<<(std::ostream& os, const Form& f);

#endif
