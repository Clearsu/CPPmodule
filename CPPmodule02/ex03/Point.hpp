/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:14:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 18:14:11 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {
	private :
		Fixed const	_x;
		Fixed const	_y;
	public :
		// OCF
		Point();
		Point(Point& p);
		Point&	operator=(Point& p);
		~Point();

		// other constructors
		Point(float fp1, float fp2);
		Point(Fixed f1, Fixed f2);

		// getter
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif
