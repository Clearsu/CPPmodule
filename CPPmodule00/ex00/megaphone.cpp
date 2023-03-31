/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:17:47 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/31 20:25:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (*(++argv))
		{
			while (**argv)
				std::cout << char(std::toupper(*(*argv)++));
		}
	}
	std::cout << std::endl;
	return 0;
}
