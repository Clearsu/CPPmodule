/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/02 17:16:43 by jincpark         ###   ########.fr       */
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
		PmergeMe* obj = PmergeMe::getInstance(argc, argv);

		for (int i = 0; i < 100; ++i) {
			vectorStart = PmergeMe::getCurrentTimeMicrosec();
			obj->sortVector();
			vectorFinish = PmergeMe::getCurrentTimeMicrosec();
			totalVec += static_cast<double>(vectorFinish - vectorStart);
		}
		std::cout <<  "\e[0;32mAverage processing time for " << obj->getVectorSize() 
			<< " elements with std::vector : " << totalVec / 100.0 << " us" << std::endl;

		double	totalDeq = 0;
		for (int i = 0; i < 100; ++i) {
			dequeStart = PmergeMe::getCurrentTimeMicrosec();
			obj->sortDeque();
			dequeFinish = PmergeMe::getCurrentTimeMicrosec();
			totalDeq += static_cast<double>(dequeFinish - dequeStart);
		}
		std::cout <<  "Average processing time for " << obj->getDequeSize() 
			<< " elements with std::deque : " << totalDeq / 100.0 << " us" << std::endl;

		obj->isSorted();

		return 0;
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	#endif

	try {
		PmergeMe* obj = PmergeMe::getInstance(argc, argv);

		obj->printVector("*** before sort ***\n", "\e[0;33m");

		vectorStart = PmergeMe::getCurrentTimeMicrosec();
		obj->sortVector();
		vectorFinish = PmergeMe::getCurrentTimeMicrosec();

		dequeStart = PmergeMe::getCurrentTimeMicrosec();
		obj->sortDeque();
		dequeFinish = PmergeMe::getCurrentTimeMicrosec();

		obj->isSorted();

		obj->printVector("*** after sort ***\n", "\e[0;36m");

		std::cout << "\e[0;32mTime to process a range of " << obj->getVectorSize()
			<< " elements with std::vector : " << (vectorFinish - vectorStart) 
			<< " us\n";
		std::cout << "Time to process a range of " << obj->getDequeSize()
			<< " elements with std::deque : " << (dequeFinish - dequeStart)
			<< " us\n";

		PmergeMe::deleteInstance();
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
