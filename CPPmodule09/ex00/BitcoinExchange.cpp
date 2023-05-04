/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:02:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 20:52:40 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>

#include "BitcoinExchange.hpp"
#include "Parser.hpp"

BitcoinExchange* BitcoinExchange::btc = 0;

BitcoinExchange::BitcoinExchange() {
	std::ifstream	infile;
	std::string		line;

	infile.open("data.csv", std::ios_base::in);
	if (infile.is_open() == false)
		throw std::runtime_error("Error: failed to open database file");
	while (true) {
		infile >> line;
		if (line == "date,exchange_rate")
			continue ;
		if (Parser::checkCsvFormat(line) == false)
			throw std::runtime_error("Error: wrong data format: " + line);
		long date = Parser::parseDate(line);
		if (date == 0)
			throw std::runtime_error("Error: wrong data format: " + line);
		double price = Parser::parsePrice(line);
		this->db.insert(std::pair<long, double>(date, price));
		if (infile.eof() == true)
			break ;
	}
	infile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { (void)src; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) { (void)src; return *this; }
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange*	BitcoinExchange::getInstance(void) {
	if (BitcoinExchange::btc == 0)
		BitcoinExchange::btc = new BitcoinExchange();
	return BitcoinExchange::btc;
}

void	BitcoinExchange::deleteInstance(void) {
	delete BitcoinExchange::btc;
}

double	BitcoinExchange::findDateAndGetPrice(const std::string& line) {
	long date = Parser::parseDate(line);
	double price;

	Parser::checkInputFormat(line);

	if (date == 0)
		throw std::runtime_error("Error: bad input => " + line);
	if (this->db.find(date) == db.end()) {
		std::map<long, double>::iterator it = db.end();
		if (date < db.begin()->first)
			throw std::runtime_error("Error: no previous date");
		while ((--it)->first > date)
			;
		price = it->second;
	}
	else
		price = this->db[date];

	return price;
}

void	BitcoinExchange::exchange(char** argv) {
	std::ifstream	infile;
	std::string		line;
	bool			start = true;

	infile.open(argv[1], std::ios_base::in);
	if (infile.is_open() == false)
		throw std::runtime_error("Error: failed to open: " + std::string(argv[1]));

	std::getline(infile, line);
	if (line != "date | value")
		throw std::runtime_error("Error: wrong input file format" + line);

	while (true) {
		std::getline(infile, line);
		if (infile.eof() == true) {
			if (start == true)
				throw std::runtime_error("Error: no information given.");
			break ;
		}
		start = false;
		try {
			double price = BitcoinExchange::findDateAndGetPrice(line);
			float count = Parser::parseCount(line);
			size_t pos = line.find(" | ", 0);

			line.erase(pos, 3);
			line.insert(pos, " => ");
			std::cout << line << " = " << count * price << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << '\n';
		}
	}
}
