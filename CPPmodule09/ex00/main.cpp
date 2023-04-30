/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:23:35 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 12:03:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <BitcoinExchange.hpp>

void checkLeak(void) {
	std::system("leaks btc");
}

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: bad arguments" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange* btc = BitcoinExchange::getInstance();
		btc->exchange(argv);
		BitcoinExchange::deleteInstance();
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
//	std::atexit(checkLeak);
	return 0;
}
