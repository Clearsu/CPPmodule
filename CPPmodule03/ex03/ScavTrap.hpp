/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:13:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/07 12:48:41 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public :
		// OCF
		ScavTrap();
		ScavTrap(const ScavTrap& s);
		ScavTrap&	operator=(const ScavTrap& s);
		virtual ~ScavTrap();

		// string constructor
		ScavTrap(const std::string name);

		// initializer
		void	initHitPoints(void);
		void	initEnergyPoints(void);
		void	initAttackDamage(void);

		// actions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void			guardGate(void);
};

#endif
