/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:03:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 16:11:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

int	main(void) {
	std::cout << "*** test1: addNumber(), longestSpan(), shortestSpan() ***\n" << std::endl;
	try {
		Span span(5);

		span.addNumber(2147483647);
		span.addNumber(-2147483648);
		span.addNumber(100);
		span.addNumber(3);
		span.addNumber(50);
		std::cout << span.longestSpan() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		span.addNumber(100);
		std::cout << span.shortestSpan() << std::endl;
	} catch (std::exception const & e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "*** test2: 1000000 addNumber() ***\n" << std::endl;
	try {
		Span span(1000000);
		std::cout << ">> adding 1000000 numbers ..." << std::endl;
		for (int i = 0; i < 1000000; ++i)
			span.addNumber(rand());
		std::cout << ">> adding done\n" << std::endl;
		span.addNumber(1);
	} catch (std::exception const & e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "*** test3: add numbers with range of iterators ***\n" << std::endl;
	try {
		std::vector<int> vec;
		for (int i = 0; i < 100000000; ++i)
			vec.push_back(rand());
		Span span(100000000);
		std::cout << ">> copying 100000000 numbers ..." << std::endl;
		span.addSequence(vec.begin(), vec.end());
		std::cout << ">> copying done\n" << std::endl;
		span.addSequence(vec.begin(), vec.end());
	} catch (std::exception const & e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return 0;
}
