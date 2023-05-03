/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/03 14:49:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int	main(int argc, char** argv) {
	std::time_t	vectorStart;
	std::time_t	vectorFinish;
	std::time_t	dequeStart;
	std::time_t	dequeFinish;

	#ifdef AVERAGE
	try {
		double	totalVec = 0;
		PmergeMe< std::vector<int> > vec(argc, argv);

		for (int i = 0; i < 100; ++i) {
			vectorStart = vec.getCurrentTimeMicrosec();
			vec.sort();
			vectorFinish = vec.getCurrentTimeMicrosec();
			totalVec += static_cast<double>(vectorFinish - vectorStart);
		}
		std::cout <<  "\e[0;32mAverage processing time for " << vec.getSize() 
			<< " elements with std::vector : " << totalVec / 100.0 << " us" << std::endl;

		vec.isSorted();

		double	totalDeq = 0;
		PmergeMe< std::deque<int> > deq(argc, argv);
		for (int i = 0; i < 100; ++i) {
			dequeStart = deq.getCurrentTimeMicrosec();
			deq.sort();
			dequeFinish = deq.getCurrentTimeMicrosec();
			totalDeq += static_cast<double>(dequeFinish - dequeStart);
		}
		std::cout <<  "Average processing time for " << deq.getSize() 
			<< " elements with std::deque : " << totalDeq / 100.0 << " us" << std::endl;

		deq.isSorted();

		return 0;

	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	#endif

	#ifdef HUGEVAL
	try {
		char*	endptr;

		long num = std::strtol(argv[1], &endptr, 10);
		if (errno == ERANGE || *endptr != '\0'
				|| num < 0 || num > std::numeric_limits<int>::max()) {
			throw std::runtime_error("Error: bad arguments");
		}

		PmergeMe< std::vector<int> > vec(num);

		vectorStart = vec.getCurrentTimeMicrosec();
		vec.sort();
		vectorFinish = vec.getCurrentTimeMicrosec();

		vec.isSorted();

		std::cout << "\e[0;32mTime to process a range of " << vec.getSize()
			<< " elements with std::vector : " << (vectorFinish - vectorStart) 
			<< " us\n";

		PmergeMe< std::deque<int> > deq(num);

		dequeStart = deq.getCurrentTimeMicrosec();
		deq.sort();
		dequeFinish = deq.getCurrentTimeMicrosec();

		deq.isSorted();

		std::cout << "Time to process a range of " << deq.getSize()
			<< " elements with std::deque : " << (dequeFinish - dequeStart)
			<< " us\n";

		return 0;

	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	#endif

	try {
		PmergeMe< std::vector<int> > vec(argc, argv);

		vec.print("*** before sort ***\n", "\e[0;33m");

		vectorStart = vec.getCurrentTimeMicrosec();
		vec.sort();
		vectorFinish = vec.getCurrentTimeMicrosec();

		vec.isSorted();

		PmergeMe< std::deque<int> > deq(argc, argv);
		dequeStart = deq.getCurrentTimeMicrosec();
		deq.sort();
		dequeFinish = deq.getCurrentTimeMicrosec();

		deq.isSorted();

		vec.print("*** after sort ***\n", "\e[0;36m");

		std::cout << "\e[0;32mTime to process a range of " << vec.getSize()
			<< " elements with std::vector : " << (vectorFinish - vectorStart) 
			<< " us\n";
		std::cout << "Time to process a range of " << deq.getSize()
			<< " elements with std::deque : " << (dequeFinish - dequeStart)
			<< " us\n";

	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
