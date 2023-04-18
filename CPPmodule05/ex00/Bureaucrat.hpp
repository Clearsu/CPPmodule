/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:27 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/17 21:27:11 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <ostream>

class	Bureaucrat
{
	private :
		const std::string	_name;
		int					_grade;
	public :
		Bureaucrat();
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat&	operator=(const Bureaucrat& src);
		~Bureaucrat();

		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				increaseGrade(void);
		void				decreaseGrade(void);

		class	GradeTooHighException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
