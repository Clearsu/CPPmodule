/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/27 14:12:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Point.hpp>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point	a(4.5f, 1.0f);
	Point	b(8.88f, 10.5f);
	Point	c(2.28f, 9.4f);
	Point	p(3.12830f, 5.23f);

	bsp(a, b, c, p);
	return 0;
}
