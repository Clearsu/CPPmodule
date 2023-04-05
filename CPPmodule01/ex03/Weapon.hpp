/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:53:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 17:44:04 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon {
	private :
		std::string	_type;
	public :
		Weapon(std::string type);
		~Weapon();

		const std::string	&getType(void);
		void				setType(std::string newType);
};

#endif
