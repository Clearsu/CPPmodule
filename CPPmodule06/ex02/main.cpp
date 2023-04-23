/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:27:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/23 14:52:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void)
{
	Base* random = generate();
	identify(random);
	identify(*random);
	delete random;
}

