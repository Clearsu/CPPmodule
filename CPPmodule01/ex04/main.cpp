/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:46:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/17 15:41:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

int	main(int argc,	char **argv) {
	if (argc != 4) {
		std::cout << "error: bad arguments\n";
		return (1);
	}
	Sed	sed(argv);
	sed.doSed();
	return (0);
}
