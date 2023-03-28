/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:25:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/28 19:07:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

typedef struct	s_vector {
	Fixed	x;
	Fixed	y;
}	t_vector;

void	setVector(t_vector& v, Fixed x1, Fixed x2, Fixed y1, Fixed y2) {
	v.x = x2 - x1;
	v.y = y2 - y1;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	t_vector	v0, v1, v2;
	Fixed		u, u1, u2;
	float		l1, l2, l3;

	setVector(v0, a.getX(), c.getX(), a.getY(), c.getY());
	setVector(v1, a.getX(), b.getX(), a.getY(), b.getY());
	setVector(v2, a.getX(), point.getX(), a.getY(), point.getY());
	u = v1.x * v0.y - v0.x * v1.y;
	u1 = v2.x * v1.y - v1.x * v2.y;
	u2 = v0.x * v2.y - v2.x * v0.y;
	std::cout << "u: " << u << " u1: " << u1 << " u2: " << u2 << std::endl;
	l1 = u1.toFloat() / u.toFloat();
	l2 = u2.toFloat() / u.toFloat();
	l3 = 1.0f - l1 - l2;
	std::cout << "l1: " << l1 << " l2: " << l2 << " l3: " << l3 << std::endl;
	if (l1 > 0 && l2 > 0 && l3 > 0)
		return true;
	return false;
}
