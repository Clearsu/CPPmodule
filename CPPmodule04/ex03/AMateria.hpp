/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:15:53 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/14 03:07:04 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class	AMateria
{
	protected:
		std::string const	_type;
    public:
		AMateria();
		AMateria(AMateria const & a);
		AMateria(std::string const & type);
		AMateria&	operator=(AMateria const & a);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
