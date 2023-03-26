/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:55:53 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/26 18:18:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char *argv[]) {
	Harl		harl;
	std::string	str;
	int			idx;
	
	if (argc != 2) {
		std::cout << "error: bad arguments" << std::endl;
		return 1;
	}
	str = argv[1];
	idx = harl.getLevelStrIdx(str);
	if (idx == -1)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else {
		switch (idx) {
			case 0 :
				std::cout << "[DEBUG]" << std::endl;
				harl.complain("DEBUG");
				std::cout << std::endl;
			case 1 :
				std::cout << "[INFO]" << std::endl;
				harl.complain("INFO");
				std::cout << std::endl;
			case 2 :
				std::cout << "[WARNING]" << std::endl;
				harl.complain("WARNING");
				std::cout << std::endl;
			case 3 :
				std::cout << "[ERROR]" << std::endl;
				harl.complain("ERROR");
				std::cout << std::endl;
		}
	}
	return 0;
}
