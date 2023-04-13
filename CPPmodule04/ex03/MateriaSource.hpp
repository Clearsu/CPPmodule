/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:31:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 19:34:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class	MateriaSource : public IMateriaSource
{
	public :
		MateriaSource();
		MateriaSource(MateriaSource const & c);
		MateriaSource&	operator=(MateriaSource const & c);
		~MateriaSource();
};

#endif
