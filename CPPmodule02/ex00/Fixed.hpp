/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/20 18:12:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {
	private :
		int					_value;
		static const int	_binaryPoint = 8;
	public :
		Fixed();
		Fixed(const Fixed &f);
		void	operator=(const Fixed &f);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
