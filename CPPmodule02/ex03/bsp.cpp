/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:25:34 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/27 23:29:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	getSlope(const Point& a, const Point& b) {
	return ((a.getY() - b.getY()) / (a.getX() - b.getX()));
}

Fixed	getYIntercept(Fixed& slope, const Point& p) {
	return (p.getY() - slope * p.getX());
}

// y = ax + b
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed a1(getSlope(a, b));
	Fixed a2(getSlope(b, c));
	Fixed a3(getSlope(a, c));
	Fixed b1(getYIntercept(a1, a));
	Fixed b2(getYIntercept(a2, b));
	Fixed b3(getYIntercept(a3, c));
	`
	return (true);
}
