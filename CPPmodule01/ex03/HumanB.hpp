/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 21:33:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB {
	private :
		std::string	name;
		Weapon		*weapon;
	public :
		HumanB(std::string newName) {
			name = newName;
		}
		void				setWeapon(Weapon &newWeapon);
		const std::string	&getName(void);
		void				attack(void);
};

#endif
