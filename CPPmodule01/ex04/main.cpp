/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:46:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/17 12:39:37 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "Sed.hpp"

int	main(int argc,	char **argv) {
	Sed				sed;
	std::ofstream	infobj;
	std::ofstream	outfobj;

	if (argc != 4) {
		std::cout << "error: bad arguments\n";
		return (1);
	}
	sed.setFilename(argv[1]);
	sed.setS1(argv[2]);
	sed.setS2(argv[3]);
	infobj.open(sed.getInFilename());
	outfobj.open(sed.getOutFilename());
	infobj.close();
	outfobj.close();
	return (0);
}
