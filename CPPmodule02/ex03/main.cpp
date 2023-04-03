/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/03 17:49:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point	a(0, 0);
	Point	b(10.4f, 0);
	Point	c(5.5f, 9.283f);

	std::cout << "> point inside of the triangle" << std::endl;
	Point	p1(5.0f, 1);
	if (bsp(a, b, c, p1))
		std::cout << "the point is in the triangle\n" << std::endl;
	else
		std::cout << "the point is not in the triangle\n" << std::endl;

	std::cout << "> point on the edge of the triangle" << std::endl;
	Point	p2(5.0f, 0);
	if (bsp(a, b, c, p2))
		std::cout << "the point is in the triangle\n" << std::endl;
	else
		std::cout << "the point is not in the triangle\n" << std::endl;

	std::cout << "> point outside of the triangle" << std::endl;
	Point	p3(5.0f, 10);
	if (bsp(a, b, c, p3))
		std::cout << "the point is in the triangle\n" << std::endl;
	else
		std::cout << "the point is not in the triangle\n" << std::endl;

	return 0;
}
