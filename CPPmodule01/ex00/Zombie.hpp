/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:55:05 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/23 20:23:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private :
		std::string	name;
	public :
		~Zombie() {
			std::cout << name << " is dead" << std::endl;
		}
		void	announce(void);
		void	setName(std::string str);
		Zombie*	newZombie(std::string name);
		void	randomChump(std::string name);
};

#endif
