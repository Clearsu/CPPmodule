/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 17:45:40 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB {
	private :
		std::string	_name;
		Weapon		*_weapon;
	public :
		HumanB(std::string name);
		~HumanB();

		void				setWeapon(Weapon &weapon);
		const std::string	&getName(void);
		void				attack(void);
};

#endif
