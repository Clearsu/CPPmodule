/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 16:55:53 by jincpark         ###   ########.fr       */
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
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &f);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		void	operator=(const Fixed& f);

		void	operator>(const Fixed& f1, const Fixed& f2);
		void	operator<(const Fixed& f1, const Fixed& f2);
		void	operator>=(const Fixed& f1, const Fixed& f2);
		void	operator<=(const Fixed& f);
		void	operator==(const Fixed& f);
		void	operator!=(const Fixed& f);

		void	operator+(const Fixed& f);
		void	operator-(const Fixed& f);
		void	operator*(const Fixed& f);
		void	operator/(const Fixed& f);


};

std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif
