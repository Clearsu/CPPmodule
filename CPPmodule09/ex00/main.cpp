/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:23:35 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 20:53:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <cstdlib>
#include <stdexcept>
#include <iostream>

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Error: bad arguments" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange* btc = BitcoinExchange::getInstance();
		btc->exchange(argv);
		BitcoinExchange::deleteInstance();
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
//	std::system("leaks btc");
	return 0;
}
