/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:55:05 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/05 17:42:41 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private :
		std::string	_name;
	public :
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(std::string name);
		Zombie	*zombieHorde(int N, std::string name);
};

#endif
