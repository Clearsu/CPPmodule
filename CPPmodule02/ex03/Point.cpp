/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:27:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/03 16:28:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	Point::getX(void) const {
	Fixed	temp(x);
	return temp;
}

Fixed	Point::getY(void) const {
	Fixed	temp(y);
	return temp;
}
