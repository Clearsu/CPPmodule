/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:26:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 19:30:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

class	Cure : public AMateria
{
	public :
		Cure();
		Cure(Cure const & c);
		Cure&	operator=(Cure const & c);
		~Cure();
};

#endif
