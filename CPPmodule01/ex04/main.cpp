/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:46:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/17 12:00:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ofstream>
#include "Sed.hpp"

int	main(int argc,	char **argv) {
	Sed			sed;
	ofstream	fout;

	if (argc != 4)
		return (1);
	sed.setFname(argv[1]);
	sed.setS1(argv[2]);
	sed.setS2(argv[3]);
	fout.open(sed.getFname());
	return (0);
}
