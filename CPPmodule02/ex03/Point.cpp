/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:27:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/26 21:23:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const Fixed&	Point::getX(void) {
	return x;
}

const Fixed&	Point::getY(void) {
	return y;
}

bool	Point::isInLine(const Point& p1, const Point& p2, const Point& point) {
}
