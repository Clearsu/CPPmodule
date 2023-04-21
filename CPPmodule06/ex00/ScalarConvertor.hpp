/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:27:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/21 17:36:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_HPP
# define SCALAR_CONVERSION_HPP

# include <string>
# include <stdexcept>

typedef enum { CHAR, INT, FLOAT, DOUBLE, NONE } eTypes;

class ScalarConvertor
{
	private :
		void	detectType(void);
	public :
		ScalarConvertor();
		ScalarConvertor(const ScalarConvertor& src);
		ScalarConvertor&	operator=(const ScalarConvertor& src);
		~ScalarConvertor();

		static void	convert(const std::string& str);

		class NonConvertableException : public exception
		{
			const char*	what(void) const throw();
		}
}

#endif
