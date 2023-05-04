/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:14:06 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 20:16:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "RPN.hpp"

std::stack<int> RPN::_stack;

RPN::RPN() {}
RPN::RPN(const RPN& src) { (void)src; }
RPN& RPN::operator=(const RPN& src) { (void)src; return *this; }
RPN::~RPN() {}

bool	RPN::isOperator(const char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int	RPN::operate(const int val1, const int val2, const char c) {
	int	res;

	switch (c) {
		case '+' :
			res = val1 + val2;
			if (res - val1 - val2 != 0)
				throw std::runtime_error("Error: overflow detected");
			break ;
		case '-' : 
			res = val1 - val2;
			if (res - val1 + val2 != 0)
				throw std::runtime_error("Error: overflow detected");
			break ;
		case '*' : 
			res = val1 * val2;
			if ((val1 > 0 && val2 > 0 && res < 0)
					|| (((val1 < 0 && val2 > 0) || (val1 > 0 && val2 < 0)) && res > 0))
				throw std::runtime_error("Error: overflow detected");
			break ;
		case '/' : 
			if (val2 == 0)
				throw std::runtime_error("Error: devide by zero");
			res = val1 / val2;
	}
	return res;
}

void	RPN::reversePolishNotation(char* argv) {
	std::stringstream	ss(argv);
	std::string			_char;
	int					val1, val2, res;

	while (true) {
		ss >> _char;
		if (_char.length() != 1)
			throw std::runtime_error("Error: invalid argument: " + _char);
		if (!std::isdigit(_char.c_str()[0]) && !RPN::isOperator(_char.c_str()[0]))
			throw std::runtime_error("Error: invalid argument: " + _char);
		if (std::isdigit(_char.c_str()[0]))
			RPN::_stack.push(_char.c_str()[0] - '0');
		else {
			if (RPN::_stack.empty())
				throw std::runtime_error("Error: number of numeric values and operators do not match");
			val2 = RPN::_stack.top();
			RPN::_stack.pop();
			if (RPN::_stack.empty())
				throw std::runtime_error("Error: number of numeric values and operators do not match");
			val1 = RPN::_stack.top();
			RPN::_stack.pop();
			res = RPN::operate(val1, val2, _char.c_str()[0]);
			RPN::_stack.push(res);
		}
		if (ss.eof() == true) {
			if (RPN::_stack.size() != 1)
				throw std::runtime_error("Error: number of numeric values and operators do not match");
			std::cout << RPN::_stack.top() << std::endl;
			return ;
		}
	}
}
