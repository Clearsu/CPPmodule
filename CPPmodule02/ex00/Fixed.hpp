/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/26 21:17:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {
	private :
		int					_value;
		static const int	_binaryPoint = 8;
	public :
		// OCF
		Fixed() : _value(0) {
			std::cout << "Default constructor called\n";
		}
		Fixed(const Fixed &f) : _value(f._value) {
			std::cout << "Copy constructor called\n";
		}
		Fixed&	operator=(const Fixed &f);
		~Fixed() {
			std::cout << "Destructor called\n";
		}

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
