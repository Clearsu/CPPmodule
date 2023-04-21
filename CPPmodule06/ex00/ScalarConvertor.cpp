/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:27:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/21 17:37:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>

#include "ScalarConvertor.hpp"

int	ScalarConvertor::detectType(const std::string& str)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = str.len();
	if (len == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return CHAR;
	while (std::isdigit(str[idx]))
		++idx;
	if (idx == len)
		return INT;
	if (str[idx] == '.')
		++idx;
	while (std::isdigit(str[idx]))
		++idx;
	if (idx == len)
		return DOUBLE;
	if (str[idx] == 'f')
		++idx;
	if (idx == len)
		return FLOAT;
	return NONE;
}

ScalarConvertor::ScalarConvertor() {}
ScalarConvertor::~ScalarConvertor() {}
ScalarConvertor::ScalarConvertor(const ScalarConvertor& src) : str(src.str) { (void)src; }
ScalarConvertor&	ScalarConvertor::operator=(const ScalarConvertor& src)
{
	(void)src;
	return *this;
}

void	ScalarConvertor::convert(const std::string& str)
{
	int		type;
	void	*value;

	type = detectType(str);
	switch (type)
	{
		case CHAR :
			value = newChar(str); break ;
		case INT :
			value = newInt(str); break ;
		case FLOAT :
			value = newFloat(str); break ;
		case DOUBLE :
			value = newDouble(str); break ;
		default :
			throw ScalarConvertor::NonConvertableException();
	}
}

const char*	ScalarConvertor::NonConvertableException::what(void) const throw()
{
	return ("error: non-convertable literal as input");
}
