/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:05:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 15:07:50 by jincpark         ###   ########.fr       */
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

		static bool	isOperator(char c);	
		static int	operate(int val1, int val2, char op);
	public :
		static void	reversePolishNotation(char* argv);
};
#endif
