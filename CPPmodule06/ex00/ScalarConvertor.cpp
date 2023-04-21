/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:27:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/21 23:35:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cerrno>
#include <limits>
#include <iostream>
#include <string>

#include "ScalarConvertor.hpp"

int	ScalarConvertor::detectType(const std::string& str)
{
	const char*	cstr;
	size_t		idx;
	size_t		len;
	bool		dotflag;
	bool		decimalflag;

	cstr = str.c_str();
	idx = 0;
	len = str.length();
	dotflag = false;
	decimalflag = false;
	if (len == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return CHAR;
	if (str[0] == '-')
		++idx;
	while (std::isdigit(str[idx]))
		++idx;
	if (idx == len)
		return INT;
	if (str[idx] == '.')
	{
		dotflag = true;
		++idx;
	}
	while (std::isdigit(str[idx]))
	{
		decimalflag = true;
		++idx;
	}
	if ((idx == len && dotflag == true && decimalflag == true)
			|| std::strcmp("nan", cstr) == 0
			|| std::strcmp("-inf", cstr) == 0
			|| std::strcmp("+inf", cstr) == 0)
		return DOUBLE;
	if (str[idx] == 'f')
		++idx;
	if ((idx == len && dotflag == true && decimalflag == true)
			|| std::strcmp("nanf", cstr) == 0
			|| std::strcmp("-inff", cstr) == 0
			|| std::strcmp("+inff", cstr) == 0)
		return FLOAT;
	return NONE;
}

void*	ScalarConvertor::newChar(const std::string& str)
{
	char*	ret;

	std::cout << "type: char" << std::endl;
	try
	{
		ret = new char;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
	}
	*ret = str[0];
	std::cout << "value: " << *ret << std::endl;
	return (void*)ret;
}

void*	ScalarConvertor::newInt(const std::string& str)
{
	int*	ret;
	long	temp;

	std::cout << "type: int" << std::endl;
	try
	{
		ret = new int;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
	}
	temp = std::strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE || temp != (int)temp)
	{
		delete ret;
		throw ScalarConvertor::RangeErrorException();
	}
	*ret = temp;
	std::cout << "value: " << *ret << std::endl;
	return (void*)ret;
}

void*	ScalarConvertor::newFloat(const std::string& str)
{
	float*	ret;

	std::cout << "type: float" << std::endl;
	try
	{
		ret = new float;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
	}
	*ret = (float)std::strtod(str.c_str(), NULL);
	if (*ret == std::numeric_limits<float>::infinity()
			|| *ret == std::numeric_limits<float>::lowest())
	{
		delete ret;
		throw ScalarConvertor::RangeErrorException();
	}
	std::cout << "value: " << *ret << std::endl;
	return (void*)ret;
}

void*	ScalarConvertor::newDouble(const std::string& str)
{
	double*	ret;

	std::cout << "type: double" << std::endl;
	try
	{
		ret = new double;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
	}
	*ret = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		delete ret;
		throw ScalarConvertor::RangeErrorException();
	}
	std::cout << "value: " << *ret << std::endl;
	return (void*)ret;
}

void	ScalarConvertor::convertToChar(void* value, int type)
{
	char	printVal;
	int		itemp;
	float	ftemp;
	double	dtemp;

	printVal = 0;
	std::cout << "char: ";
	switch (type)
	{
		case CHAR :
			printVal = static_cast<char>(*((char *)value));
			break ;
		case INT :
			itemp = *(int *)value;
			if (itemp < 0 || itemp > 127)
			{
				std::cout << "impossible";
				break ;
			}
			else if (std::isprint(itemp) == false)
			{
				std::cout << "Non displayable";
				break ;
			}
			printVal = static_cast<char>(itemp);
			break ;
		case FLOAT :
			ftemp = *(float *)value;
			if (ftemp < 0.0f || ftemp > 127.0f || ftemp - (int)ftemp != 0.0f)
			{
				std::cout << "impossible";
				break ;
			}
			if (std::isprint((int)ftemp) == false)
			{
				std::cout << "Non displayable";
				break ;
			}
			printVal = static_cast<char>(ftemp);
			break ;
		case DOUBLE :
			dtemp = *(double *)value;
			if (dtemp < 0.0 || dtemp > 127.0 || dtemp - (long)dtemp != 0.0)
			{
				std::cout << "impossible";
				break ;
			}
			if (std::isprint((int)dtemp) == false)
			{
				std::cout << "Non displayable";
				break ;
			}
			printVal = static_cast<char>(dtemp);
			break ;
	}
	std::cout << printVal << std::endl;
}

ScalarConvertor::ScalarConvertor() {}
ScalarConvertor::~ScalarConvertor() {}
ScalarConvertor::ScalarConvertor(const ScalarConvertor& src) { (void)src; }
ScalarConvertor&	ScalarConvertor::operator=(const ScalarConvertor& src)
{
	(void)src;
	return *this;
}

void	ScalarConvertor::convert(const std::string& str)
{
	int		type;
	void*	value;

	type = detectType(str);
	switch (type)
	{
		case CHAR :
			value = ScalarConvertor::newChar(str); break ;
		case INT :
			value = ScalarConvertor::newInt(str); break ;
		case FLOAT :
			value = ScalarConvertor::newFloat(str); break ;
		case DOUBLE :
			value = ScalarConvertor::newDouble(str); break ;
		default :
			throw ScalarConvertor::NonConvertableException();
	}
	ScalarConvertor::convertToChar(value, type);
}

const char*	ScalarConvertor::NonConvertableException::what(void) const throw()
{
	return ("error: non-convertable literal as input");
}

const char*	ScalarConvertor::RangeErrorException::what(void) const throw()
{
	return ("error: out of range");
}
