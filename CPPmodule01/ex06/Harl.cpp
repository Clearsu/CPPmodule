/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:58:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/26 18:14:58 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

//private
void	Harl::debug(void) const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) const {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

//public
Harl::Harl(void) {
	levelStr[0] = "DEBUG";
	levelStr[1] = "INFO";
	levelStr[2] = "WARNING";
	levelStr[3] = "ERROR";
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
}

void	Harl::complain(std::string level) {
	for (int i = 0; i < 4; ++i) {
		if (level == levelStr[i]) {
			(this->*func[i])();
			return ;
		}
	}
}

int		Harl::getLevelStrIdx(std::string level) {
	for (int i = 0; i < 4; ++i) {
		if (level == levelStr[i])
			return i;
	}
	return -1;
}
