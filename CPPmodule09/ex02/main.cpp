/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/01 12:27:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <PmergeMe.hpp>

int	main(int argc, char** argv) {
	try {
		PmergeMe* obj = PmergeMe::getInstance(argc, argv);	
		obj = obj->getInstance(argc, argv);
		obj->printVector();
		obj->sortVector();
		obj->printVector();
		PmergeMe::deleteInstance();
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}
