/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 17:56:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {
	private :
		int					_rawBits;
		static const int	_fracBits = 8;
	public :
		// OCF
		Fixed();
		Fixed(const Fixed &f);
		Fixed&	operator=(const Fixed &f);
		~Fixed();

		// other constructors
		Fixed(const int value);
		Fixed(const float value);

		// basic member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// relational operators
		bool	operator>(const Fixed& f);
		bool	operator<(const Fixed& f);
		bool	operator>=(const Fixed& f);
		bool	operator<=(const Fixed& f);
		bool	operator==(const Fixed& f);
		bool	operator!=(const Fixed& f);

		// arithmetic operators
		Fixed	operator+(const Fixed& f);
		Fixed	operator-(const Fixed& f);
		Fixed	operator*(const Fixed& f);
		Fixed	operator/(const Fixed& f);

		// min and max member functions
		static Fixed&	min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

		// overloading increment and decrement operators
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);
};

// << overloading
std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif
