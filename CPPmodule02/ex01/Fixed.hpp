/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/26 16:52:37 by jincpark         ###   ########.fr       */
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
		//OCF
		Fixed() : _rawBits(0) {
			std::cout << "Default constructor called\n";
		}
		Fixed(const Fixed &f) : _rawBits(f._rawBits) {
			std::cout << "Copy constructor called\n";
		}
		Fixed&	operator=(const Fixed& f);
		~Fixed() {
			std::cout << "Destructor called\n";
		}

		// other constructors
		Fixed(const int value);
		Fixed(const float value);

		// member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// overloading operator<<
std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif
