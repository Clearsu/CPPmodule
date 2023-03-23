/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:52:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/23 20:36:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

Sed::Sed(char **argv) {
	std::string fname;

	fname = argv[1];
	infile.open(fname);
	outfile.open(fname.append(".replace"));
	s1 = argv[2];
	s2 = argv[3];
}

Sed::~Sed() {
	infile.close();
	outfile.close();
}

void	Sed::doSed(void) {
	std::string	line;
	size_t		lens1 = s1.length();
	size_t		pos;

	while (std::getline(infile, line)) {
		pos = 0;
		pos = line.find(s1, pos);
		while (pos != std::string::npos) {
			line.erase(pos, lens1);
			line.insert(pos, s2);
			pos = line.find(s1, pos);
		}
		outfile << line << std::endl;
	}
}
