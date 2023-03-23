/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:32:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/23 20:28:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "address of the string variable: " << &string << '\n';
	std::cout << "address held by stringPTR: " << stringPTR << '\n';
	std::cout << "address held by stringREF: " << &stringREF << "\n\n";
	std::cout << "value of the string variable: " << string << '\n';
	std::cout << "value pointed by stringPTR: " << *stringPTR << '\n';
	std::cout << "value pointed by stringREF: " << stringREF << std::endl;
	return 0;
}
