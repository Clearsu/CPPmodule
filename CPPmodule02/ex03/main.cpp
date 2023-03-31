/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/30 18:11:36 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Point.hpp>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point	a(0, 0);
	Point	b(10.4f, 0);
	Point	c(5.5f, 9.283f);
	Point	p(5.0f, 2.21f);

	if (bsp(a, b, c, p))
		std::cout << "the point is in the triangle" << std::endl;
	else
		std::cout << "the point is not in the triangle" << std::endl;
	return 0;
}
