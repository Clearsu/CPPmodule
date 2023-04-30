/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:00:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 15:11:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <RPN.hpp>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: bad arguments" << std::endl;
		return 1;
	}
	try {
		RPN::reversePolishNotation(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
