/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/28 16:35:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <MutantStack.hpp>

void	mytest(void) {	
		std::cout << "***** my own test *****" << std::endl;
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

void	subject_test(void) {
		std::cout << "***** test from the subject *****" << std::endl;
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

int main(void) {
	mytest();
	subject_test();

	return 0;
}
