/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 17:50:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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

		// getter and setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
