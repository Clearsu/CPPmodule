/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 19:03:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK_HPP__
#define __MUTANT_STACK_HPP__

#include <stack>

template <typename T, typename Cont = std::deque<T> >
class	MutantStack : public std::stack<T, Cont> {
	public :
		MutantStack() : std::stack<T, Cont>() {}
		MutantStack(const MutantStack& src) : std::stack<T, Cont>(src) {}
		MutantStack& operator=(const MutantStack& src) {
			if (this != &src)
				*this = src;
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T, Cont>::container_type::iterator iterator;
		typedef typename std::stack<T, Cont>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, Cont>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T, Cont>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator			begin(void) { return std::stack<T>::c.begin(); }
		iterator			end(void) { return std::stack<T>::c.end(); }
		reverse_iterator	rbegin(void) { return std::stack<T>::c.rbegin(); }
		reverse_iterator	rend(void) { return std::stack<T>::c.rend(); }
};

#endif
