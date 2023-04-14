/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:31:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/15 03:57:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>

# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
		Ice*	_ice;
		Cure*	_cure;
	public :
		MateriaSource();
		MateriaSource(MateriaSource const & c);
		MateriaSource&	operator=(MateriaSource const & c);
		~MateriaSource();

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif
