/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:27:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/22 02:09:44 by jincpark         ###   ########.fr       */
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
		static int		detectType(const std::string& str);
		static void*	newChar(const std::string& str);
		static void*	newInt(const std::string& str);
		static void*	newFloat(const std::string& str);
		static void*	newDouble(const std::string& str);

		static void	convertToChar(void* value, int type);
		static void	convertToInt(void* value, int type);
		static void	convertToFloat(void* value, int type);
		static void	convertToDouble(void* value, int type);
	public :
		ScalarConvertor();
		ScalarConvertor(const ScalarConvertor& src);
		ScalarConvertor&	operator=(const ScalarConvertor& src);
		~ScalarConvertor();

		static void	convert(const std::string& str);

		class	NonConvertableException : public std::exception
		{
			const char*	what(void) const throw();
		};
		class	RangeErrorException : public std::exception
		{
			const char* what(void) const throw();
		};
};

#endif
