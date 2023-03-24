/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:02:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 20:22:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CPP
# define HUMANA_CPP

# include "Weapon.hpp"

class	HumanA {
	private :
		std::string	_name;
		Weapon& 	_weapon;
	public :
		HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}
		const std::string&	getName(void);
		void				attack(void);
};

#endif
