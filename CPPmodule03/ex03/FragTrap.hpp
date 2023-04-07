/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:54:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/07 12:48:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public :
		// OCF
		FragTrap();
		FragTrap(const FragTrap& s);
		FragTrap&	operator=(const FragTrap& s);
		virtual ~FragTrap();

		// string constructor
		FragTrap(const std::string name);

		// initializer
		void	initHitPoints(void);
		void	initEnergyPoints(void);
		void	initAttackDamage(void);
		// actions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);
};

#endif
