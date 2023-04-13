/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:27:27 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 19:30:18 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

class	Ice : public AMateria
{
	public :
		Ice();
		Ice(Ice const & c);
		Ice&	operator=(Ice const & c);
		~Ice();
};

#endif
