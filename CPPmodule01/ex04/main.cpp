/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:46:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 18:55:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

int	main(int argc,	char **argv) {
	if (argc != 4) {
		std::cerr << "error: bad arguments" << std::endl;
		return 1;
	}
	Sed	sed(argv);
	sed.doSed();
	return 0;
}
