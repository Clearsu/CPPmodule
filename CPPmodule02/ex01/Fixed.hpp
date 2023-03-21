/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/21 22:56:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define MANTISSA_LEN 23
# define EXPONENT_BIAS 127

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

		void			operator=(const Fixed &f);
		std::ostream	&operator<<(std::ostream &os, const Fixed &f);
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
};

#endif
