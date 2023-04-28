/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/28 16:43:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK_HPP__
#define __MUTANT_STACK_HPP__

#include <stack>

template <typename T>
class	MutantStack : public std::stack<T> {
	public :
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& src) : std::stack<T>(src) {}
		MutantStack& operator=(const MutantStack& src) {
			if (this == &src)
				return *this;
			this->~MutantStack();
			this->~stack();
			new (this) MutantStack(src);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator			begin(void) { return std::stack<T>::c.begin(); }
		iterator			end(void) { return std::stack<T>::c.end(); }
		reverse_iterator	rbegin(void) { return std::stack<T>::c.rbegin(); }
		reverse_iterator	rend(void) { return std::stack<T>::c.rend(); }
};

#endif
