/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:52:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/17 13:25:42 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

const std::string	&Sed::getInFilename(void) {
	const std::string	&ret = infile;
	return (ret);
}

const std::string	&Sed::getOutFilename(void) {
	const std::string	&ret = outfile;
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

void	Sed::setFilename(std::string str) {
	infile = str;
	outfile = str.append(".replace");
}

void	Sed::setS1(std::string str) {
	s1 = str;
}

void	Sed::setS2(std::string str) {
	s2 = str;
}
