/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:27:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/25 10:01:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cerrno>
#include <limits>
#include <iostream>
#include <string>
#include <cmath>

#include "ScalarConvertor.hpp"

ScalarConvertor::ScalarConvertor() {}
ScalarConvertor::~ScalarConvertor() {}
ScalarConvertor::ScalarConvertor(const ScalarConvertor& src) { (void)src; }
ScalarConvertor&	ScalarConvertor::operator=(const ScalarConvertor& src)
{
	(void)src;
	return *this;
}

int	ScalarConvertor::detectType(const std::string& str)
{
	size_t		idx;
	size_t		len;
	bool		dotflag;
	bool		decimalflag;

	idx = 0;
	len = str.length();
	dotflag = false;
	decimalflag = false;
	if (len == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return CHAR;
	if (str[0] == '-' || str[0] == '+')
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
			|| str == "nan" || str == "inf"
			|| str == "+inf" || str == "-inf")
		return DOUBLE;
	if (str[idx] == 'f')
		++idx;
	if ((idx == len && dotflag == true && decimalflag == true)
			|| str == "nanf" || str == "inff"
			|| str == "+inff" || str == "-inff")
		return FLOAT;
	return NONE;
}

void*	ScalarConvertor::newChar(const std::string& str)
{
	char*	ret;

	ret = new char;
	*ret = str[0];
	return static_cast<void*>(ret);
}

void*	ScalarConvertor::newInt(const std::string& str)
{
	int*	ret;
	long	temp;

	ret = new int;
	temp = std::strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE || temp != (int)temp)
	{
		delete ret;
		throw ScalarConvertor::RangeErrorException();
	}
	*ret = temp;
	return static_cast<void*>(ret);
}

void*	ScalarConvertor::newFloat(const std::string& str)
{
	float*	ret;

	ret = new float;
	*ret = static_cast<float>(std::strtod(str.c_str(), NULL));
	if (errno == ERANGE)
	{
		delete ret;
		throw ScalarConvertor::RangeErrorException();
	}
	return static_cast<void*>(ret);
}

void*	ScalarConvertor::newDouble(const std::string& str)
{
	double*	ret;

	ret = new double;
	*ret = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		delete ret;
		throw ScalarConvertor::RangeErrorException();
	}
	return static_cast<void*>(ret);
}

void	ScalarConvertor::convertToChar(void* value, int type)
{
	char	printVal;
	int		itemp;
	float	ftemp;
	double	dtemp;
	bool	eflag;

	printVal = 0;
	eflag = false;
	std::cout << "char: ";
	switch (type)
	{
		case CHAR :
			printVal = *(static_cast<char *>(value));
			break ;
		case INT :
			itemp = *(static_cast<int *>(value));
			if (itemp < 0 || itemp > 127)
			{
				std::cout << "impossible" << std::endl;
				eflag = true;
				break ;
			}
			else if (std::isprint(itemp) == false)
			{
				std::cout << "Non displayable" << std::endl;
				eflag = true;
				break ;
			}
			printVal = static_cast<char>(itemp);
			break ;
		case FLOAT :
			ftemp = *(static_cast<float *>(value));
			if (ftemp < 0 || ftemp > 127 || ftemp - static_cast<int>(ftemp) != 0.0f)
			{
				std::cout << "impossible" << std::endl;
				eflag = true;
				break ;
			}
			if (std::isprint(static_cast<int>(ftemp)) == false)
			{
				std::cout << "Non displayable" << std::endl;
				eflag = true;
				break ;
			}
			printVal = static_cast<char>(ftemp);
			break ;
		case DOUBLE :
			dtemp = *(static_cast<double *>(value));
			if (dtemp < 0 || dtemp > 127 || dtemp - static_cast<long>(dtemp) != 0.0)
			{
				std::cout << "impossible" << std::endl;
				eflag = true;
				break ;
			}
			if (std::isprint(static_cast<int>(dtemp)) == false)
			{
				std::cout << "Non displayable" << std::endl;
				eflag = true;
				break ;
			}
			printVal = static_cast<char>(dtemp);
	}
	if (eflag == false)
		std::cout << printVal << std::endl;
}

void	ScalarConvertor::convertToInt(void* value, int type)
{
	int		printVal;
	char	ctemp;
	float	ftemp;
	double	dtemp;
	bool	eflag;


	eflag = false;
	std::cout << "int: ";
	switch(type)
	{
		case CHAR :
			ctemp = *(static_cast<char *>(value));
			printVal = static_cast<int>(ctemp);
			break ;
		case INT :
			printVal = *(static_cast<int *>(value));
			break ;
		case FLOAT :
			ftemp = *(static_cast<float *>(value));
			if (ftemp > std::numeric_limits<int>::max()
					|| ftemp < std::numeric_limits<int>::lowest()
					|| std::isnan(ftemp))
			{
				std::cout << "impossible" << std::endl;
				eflag = true;
				break ;
			}
			printVal = static_cast<int>(ftemp);
			break ;
		case DOUBLE :
			dtemp = *(static_cast<double *>(value));
			if (dtemp > std::numeric_limits<int>::max()
					|| dtemp < std::numeric_limits<int>::lowest()
					|| std::isnan(dtemp))
			{
				std::cout << "impossible" << std::endl;
				eflag = true;
				break ;
			}
			printVal = static_cast<int>(dtemp);
	}
	if (eflag == false)
		std::cout << printVal << std::endl;
}

void	ScalarConvertor::convertToFloat(void* value, int type)
{
	float	printVal;
	char	ctemp;
	int		itemp;
	double	dtemp;
	bool	eflag;

	eflag = false;
	std::cout << "float: ";
	switch (type)
	{
		case CHAR :
			ctemp = *(static_cast<char *>(value));
			printVal = static_cast<float>(ctemp);
			break ;
		case INT :
			itemp = *(static_cast<int *>(value));
			printVal = static_cast<float>(itemp);
			break ;
		case FLOAT :
			printVal = *(static_cast<float *>(value));
			break ;
		case DOUBLE :
			dtemp = *(static_cast<double *>(value));
			if (dtemp > std::numeric_limits<float>::max()
					|| dtemp < std::numeric_limits<float>::lowest())
			{
				std::cout << "impossible" << std::endl;
				eflag = true;
			}
			printVal = static_cast<float>(dtemp);
	}
	if (eflag == false)
	{
		std::cout << printVal;
		if (printVal < 1e6f && printVal > -1e6f && printVal == static_cast<int>(printVal))
			std::cout << ".0";
		std::cout << 'f' << std::endl;
	}
}

void	ScalarConvertor::convertToDouble(void* value, int type)
{
	double	printVal;
	char	ctemp;
	int		itemp;
	float	ftemp;

	std::cout << "double: ";
	switch (type)
	{
		case CHAR :
			ctemp = *(static_cast<char *>(value));
			printVal = static_cast<double>(ctemp);
			break ;
		case INT :
			itemp = *(static_cast<int *>(value));
			printVal = static_cast<double>(itemp);
			break ;
		case FLOAT :
			ftemp = *(static_cast<float *>(value));
			printVal = static_cast<double>(ftemp);
			break ;
		case DOUBLE :
			printVal = *(static_cast<double *>(value));
	}
	std::cout << printVal;
	if (printVal < 1e6 && printVal > -1e6 && printVal == static_cast<int>(printVal))
		std::cout << ".0";
	std::cout << std::endl;
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
	ScalarConvertor::convertToInt(value, type);
	ScalarConvertor::convertToFloat(value, type);
	ScalarConvertor::convertToDouble(value, type);

	char*	ctemp;
	int*	itemp;
	float*	ftemp;
	double*	dtemp;

	switch (type)
	{
		case CHAR :
			ctemp = static_cast<char *>(value);
			delete ctemp;
			break ;
		case INT :
			itemp = static_cast<int *>(value);
			delete itemp;
			break ;
		case FLOAT :
			ftemp = static_cast<float *>(value);
			delete ftemp;
			break ;
		case DOUBLE :
			dtemp = static_cast<double *>(value);
			delete dtemp;
	}
}

const char*	ScalarConvertor::NonConvertableException::what(void) const throw()
{
	return ("error: non-convertable literal as input");
}

const char*	ScalarConvertor::RangeErrorException::what(void) const throw()
{
	return ("error: out of range");
}
