/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:52:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 18:56:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

Sed::Sed(char **argv) {
	std::string fname;

	fname = argv[1];
	infile.open(fname, std::ios_base::in);
	if (!infile.is_open()) {
		std::cerr << "error: failed to open the file" << std::endl;
		exit(1);
	}
	outfile.open(fname.append(".replace"), std::ios_base::out);
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
