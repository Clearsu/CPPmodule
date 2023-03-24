/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 21:59:33 by jincpark         ###   ########.fr       */
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
		Fixed() : _rawBits(0) {
			std::cout << "Default constructor called\n";
		}
		Fixed(const Fixed &f) : _rawBits(f._rawBits) {
			std::cout << "Copy constructor called\n";
		}
		void	operator=(const Fixed& f);
		~Fixed() {
			std::cout << "Destructor called\n";
		}

		// other constructors
		Fixed(const int value);
		Fixed(const float value);

		// basic member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// relational operators
		void	operator>(const Fixed& f1, const Fixed& f2);
		void	operator<(const Fixed& f1, const Fixed& f2);
		void	operator>=(const Fixed& f1, const Fixed& f2);
		void	operator<=(const Fixed& f);
		void	operator==(const Fixed& f);
		void	operator!=(const Fixed& f);

		// arithmetic operators
		void	operator+(const Fixed& f);
		void	operator-(const Fixed& f);
		void	operator*(const Fixed& f);
		void	operator/(const Fixed& f);

		// min and max member functions
		static Fixed&	min(Fixed& f1, Fixed& f2);
		static Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
		static Fixed&	max(const Fixed& f1, const Fixed& f2);
}

// << overloading
std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif
