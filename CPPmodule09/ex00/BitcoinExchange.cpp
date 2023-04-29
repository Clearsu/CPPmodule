/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:02:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 01:04:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>

#include <BitcoinExchange.hpp>
#include <Parser.hpp>

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
		if (infile.eof() == true)
			break ;
		if (Parser::checkCsvFormat(line) == false)
			throw std::runtime_error("Error: wrong data format: " + line);
		long date = Parser::parseDate(line);
		if (date == 0)
			throw std::runtime_error("Error: wrong data format: " + line);
		double price = Parser::parsePrice(line);
		this->db.insert(std::pair<long, double>(date, price));
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

void	BitcoinExchange::exchange(char** argv) {
	std::ifstream	infile;
	std::string		line;

	infile.open(argv[1], std::ios_base::in);
	if (infile.is_open() == false)
		throw std::runtime_error("Error: failed to open: " + std::string(argv[1]));
	std::getline(infile, line);
	if (line != "date | value")
		throw std::runtime_error("Error: wrong input file format" + line);
	while (true) {
		std::getline(infile, line);
		if (infile.eof() == true)
			break ;
		try {
			Parser::checkInputFormat(line);
			long date = Parser::parseDate(line);
			if (date == 0)
				throw std::runtime_error("Error: bad input => " + line);
			double price;
			while (this->db.find(date) == db.end())
				--date;
			price = this->db[date];
			float count = Parser::parseCount(line);
			size_t pos = line.find(" | ", 0);
			line.erase(pos, 3);
			line.insert(pos, " => ");
			std::cout << line << " = " << count * price << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}
