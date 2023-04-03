/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:25:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/03 16:36:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Point v0(c.getX() - a.getX(), c.getY() - a.getY());
	Point v1(b.getX() - a.getX(), b.getY() - a.getY());
	Point v2(point.getX() - a.getX(), point.getY() - a.getY());
	Fixed u(v0.getX() * v1.getY() - v1.getX() * v0.getY());
	Fixed u1(v2.getX() * v1.getY() - v1.getX() * v2.getY());
	Fixed u2(v0.getX() * v2.getY() - v2.getX() * v0.getY());
	std::cout << "u: " << u << " u1: " << u1 << " u2: " << u2 << std::endl;
	Fixed l1(u1 / u);
	Fixed l2(u2 / u);
	Fixed l3(Fixed(1)  - l1 - l2);
	std::cout << "l1: " << l1 << " l2: " << l2 << " l3: " << l3 << std::endl;
	if (l1 > 0 && l2 > 0 && l3 > 0)
		return true;
	return false;
}
