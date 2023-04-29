/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:26:35 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 01:30:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <iostream>
#include <Parser.hpp>

Parser::Parser() {}
Parser::Parser(const Parser& src) { (void)src; }
Parser& Parser::operator=(const Parser& src) { (void)src; return *this; }
Parser::~Parser() {}

long	Parser::getLastDayOfMonth(long year, long month) {
	if (month >= 8)
		return ((month & 1) == 1) ? 30 : 31;
	if (month == 2)
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
	return ((month & 1) == 1) ? 31 : 30;
}

bool	Parser::checkCsvFormat(const std::string& line) {
	if (line.length() < 12)
		return false;
	if (line[4] != '-' || line[7] != '-' || line[10] != ',')
	for (int i = 0; i < 4; ++i) {
		if (std::isdigit(line[i]) == false)
			return false;
	}
	for (int i = 5; i < 7; ++i) {
		if (std::isdigit(line[i]) == false)
			return false;
	}
	for (int i = 8; i < 10; ++i) {
		if (std::isdigit(line[i]) == false)
			return false;
	}

	double	value;
	char*	endptr = 0;

	value = std::strtod(&(line.c_str()[11]), &endptr);
	if (*endptr != '\0' || value < 0.0 || errno == ERANGE)
		return false;
	return true;
}

long	Parser::parseDate(const std::string& line) {
	long	year;
	long	month;
	long	day;
	char*	endptr = 0;

	year = std::strtol(line.c_str(), &endptr, 10);
	month = std::strtol(endptr + 1, &endptr, 10);
	if (month < 1 || month > 12)
		return 0;
	day = std::strtol(endptr + 1, &endptr, 10);
	if (day < 1 || day > Parser::getLastDayOfMonth(year, month))
		return 0;
	return (year << 32) + (month << 16) + day;
}

double	Parser::parsePrice(const std::string& line) {
	return std::strtod(line.c_str() + 11, NULL);
}

void	Parser::checkInputFormat(const std::string& line) {
	if (line.length() < 14)
		throw std::runtime_error("Error: bad input => " + line);
	if (line[4] != '-' || line[7] != '-' || line[10] != ',')
	for (int i = 0; i < 4; ++i) {
		if (std::isdigit(line[i]) == false)
			throw std::runtime_error("Error: bad input => " + line);
	}
	for (int i = 5; i < 7; ++i) {
		if (std::isdigit(line[i]) == false)
			throw std::runtime_error("Error: bad input => " + line);
	}
	for (int i = 8; i < 10; ++i) {
		if (std::isdigit(line[i]) == false)
			throw std::runtime_error("Error: bad input => " + line);
	}
	if (line.find(" | ", 0) != 10)
		throw std::runtime_error("Error: bad input => " + line);

	double	value;
	char*	endptr = 0;

	value = std::strtod(&(line.c_str()[line.find(" | ", 0) + 3]), &endptr);
	if (*endptr != '\0')
		throw std::runtime_error("Error: bad input => " + line);
	if (value <= 0.0)
		throw std::runtime_error("Error: not a positive number.");
	if (value >= 1000.0)
		throw std::runtime_error("Error: too large a number.");
}

float	Parser::parseCount(const std::string& line) {
	return static_cast<float>(std::strtod(&(line.c_str()[line.find(" | ", 0) + 3]), NULL));
}
