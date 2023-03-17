/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:52:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/17 11:57:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

const std::string	&Sed::getFname(void) {
	const std::string	&ret = fname;
	return (ret);
}

const std::string	&Sed::getS1(void) {
	const std::string	&ret = s1;
	return (ret);
}

const std::string	&Sed::getS2(void) {
	const std::string	&ret = s2;
	return (ret);
}

void	Sed::setFname(std::string str) {
	fname = str;
}

void	Sed::setS1(std::string str) {
	s1 = str;
}

void	Sed::setS2(std::string str) {
	s2 = str;
}
