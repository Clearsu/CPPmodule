/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:25:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/27 14:16:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	getSlope(Point const a, Point const b) {
	return ((a.getY() - b.getY()) / (a.getX() - b.getX()));
}

// y = ax + b
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	a1, a2, a3;
	Fixed	b1, b2, b3;

	a1 = getSlope(a, b);
	a2 = getSlope(b, c);
	a3 = getSlope(a, c);
}
