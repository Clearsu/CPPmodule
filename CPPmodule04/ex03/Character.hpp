/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:24:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/14 14:51:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private :
		std::string const	_name;
		AMateria*			_inventory[4];
	public :
		Character();
		Character(Character const & c);
		Character(std::string const name);
		Character&	operator=(Character const & c);
		~Character();

		std::string const &	getName(void) const ;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
