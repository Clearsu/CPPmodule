/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:00:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/01 08:24:14 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <RPN.hpp>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: bad arguments" << std::endl;
		return 1;
	}
	try {
		RPN::reversePolishNotation(argv[1]);
	} catch (const std::exception &e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
