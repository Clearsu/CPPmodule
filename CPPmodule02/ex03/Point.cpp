/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:27:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 18:14:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// OCF
Point::Point() : _x(0), _y(0) {}

Point::Point(Point& p) : _x(p._x), _y(p._y) {}

Point&	Point::operator=(Point& p) {
	this->~Point();
	new (this) Point(p);
	return *this;
}

Point::~Point() {}

// other constructors
Point::Point(float fp1, float fp2) : _x(Fixed(fp1)), _y(Fixed(fp2)) {}

Point::Point(Fixed f1, Fixed f2) : _x(f1), _y(f2) {}

// getter
Fixed	Point::getX(void) const {
	return Fixed(_x);
}

Fixed	Point::getY(void) const {
	return Fixed(_y);
}
