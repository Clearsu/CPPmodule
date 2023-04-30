/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:14:06 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 15:18:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <RPN.hpp>

std::stack<int> RPN::_stack;

RPN::RPN() {}
RPN::RPN(const RPN& src) { (void)src; }
RPN& RPN::operator=(const RPN& src) { (void)src; return *this; }
RPN::~RPN() {}

bool	RPN::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int	RPN::operate(int val1, int val2, char c) {
	switch (c) {
		case '+' : return val1 + val2;
		case '-' : return val1 - val2;
		case '*' : return val1 * val2;
		case '/' : 
			if (val2 == 0)
				throw std::runtime_error("Error: devide by zero");
			return val1 / val2;
	}
	return 0;
}

void	RPN::reversePolishNotation(char* argv) {
	std::stringstream	ss(argv);
	std::string			_char;
	int					val1, val2, res;

	while (true) {
		ss >> _char;
		if (_char.length() == 1) {
			if (_char.c_str()[0] >= '0' && _char.c_str()[0] <= '9')
				RPN::_stack.push(_char.c_str()[0] - '0');
			else if (RPN::isOperator(_char.c_str()[0])) {
				if (RPN::_stack.empty())
					break ;
				val2 = RPN::_stack.top();
				RPN::_stack.pop();
				if (RPN::_stack.empty())
					break ;
				val1 = RPN::_stack.top();
				RPN::_stack.pop();
				res = RPN::operate(val1, val2, _char.c_str()[0]);
				RPN::_stack.push(res);
			} else break ;
		} else break ;
		if (ss.eof() == true) {
			std::cout << RPN::_stack.top() << std::endl;
			return ;
		}
	}
	throw std::runtime_error("Error: invalid argument: " + _char);
}
