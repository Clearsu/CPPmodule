/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:05:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 19:58:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <stack>

class	RPN {
	private :
		static std::stack<int> _stack;

		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();

		static bool	isOperator(const char c);	
		static int	operate(const int val1, const int val2, const char op);
	public :
		static void	reversePolishNotation(char* argv);
};
#endif
