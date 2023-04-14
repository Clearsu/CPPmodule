/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:36:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/15 03:55:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

# define MAXITEM 10

class	Floor
{
	private :
		AMateria*	_dropped[MAXITEM];
	public :
		Floor();
		Floor(const Floor& c);
		Floor&	operator=(const Floor& c);
		~Floor();

		void			setDropped(AMateria* m);
		const AMateria*	unsetDropped(const AMateria* m);
};

#endif
