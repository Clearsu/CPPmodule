/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 19:20:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

void	myTest(void) {	
		std::cout << "\e[0;32m***** my own test *****" << std::endl;
		MutantStack<int> mstack;
		
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "empty: " << mstack.empty() << std::endl;
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "popped from mstack" << std::endl;
		std::cout << "top: " << mstack.top() << std::endl;

		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator end = mstack.end();
		std::cout << "current elements in order: ";
		while (it != end) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		// testing const_iterator
		// *it = 10;
		
		MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator rend = mstack.rend();
		std::cout << "current elements in reverse order: ";
		while (rit != rend) {
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		MutantStack<int> copy = mstack;
		it = copy.begin();
		end = copy.end();
		std::cout << "current elements in order in the copy: ";
		while (it != end) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << '\n' << std::endl;
}

void	subjectTest(void) {
		std::cout << "\e[0;33m***** test from the subject *****" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite) {
		    std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack); 
}

void	subjectTestWithList(void) {
		std::cout << "\n\e[0;36m***** test from the subject replaced with list *****" << std::endl;
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << lst.back() << std::endl;

		lst.pop_back();

		std::cout << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;

		while (it != ite) {
		    std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(lst); 
}

int main(void) {
	try {
		myTest();
		subjectTest();
		subjectTestWithList();
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}
