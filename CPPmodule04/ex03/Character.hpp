/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:24:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 19:34:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class	Character : public ICharacter
{
	public :
		Character();
		Character(Character const & c);
		Character&	operator=(Character const & c);
		~Character();
};

#endif
