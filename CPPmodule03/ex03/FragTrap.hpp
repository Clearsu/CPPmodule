/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:54:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 14:39:58 by jincpark         ###   ########.fr       */
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
		virtual void	initHitPoints(void);
		virtual void	initEnergyPoints(void);
		virtual void	initAttackDamage(void);
		// actions
		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);
};

#endif
