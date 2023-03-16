/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:02:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/16 21:21:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CPP
# define HUMANA_CPP

# include "Weapon.hpp"

class	HumanA {
	private :
		std::string	name;
		Weapon 		*weapon;
	public :
		HumanA(std::string newName, Weapon &newWeapon) {
			name = newName;
			weapon = &newWeapon;
		}
		const std::string	&getName(void);
		void	attack(void);
};

#endif