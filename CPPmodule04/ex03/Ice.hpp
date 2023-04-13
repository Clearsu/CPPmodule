/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:27:27 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/14 03:22:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
	public :
		Ice();
		Ice(Ice const & c);
		Ice&	operator=(Ice const & c);
		~Ice();
		
		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif
