/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:14:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/30 18:00:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {
	private :
		Fixed const	x;
		Fixed const	y;
	public :
		Point() : x(0), y(0) {}
		Point(float fp1, float fp2) : x(Fixed(fp1)), y(Fixed(fp2)) {}
		Point(Fixed f1, Fixed f2) : x(f1), y(f2) {}
		Point(Point& p) : x(p.x), y(p.y) {}
		Point&	operator=(Point& p) {
			this->~Point();
			new (this) Point(p);
			return *this;
		}
		~Point() {}

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif