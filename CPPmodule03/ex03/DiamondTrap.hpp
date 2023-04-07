/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/07 12:57:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string	_name;
	public :
		DiamondTrap();
		//DiamondTrap(const DiamondTrap& s);
		//DiamondTrap&	operator=(const DiamondTrap& s);
		~DiamondTrap();

		// string constructor
		DiamondTrap(const std::string name);

		void	initHitPoints(void);
		void	initEnergyPoints(void);
		void	initAttackDamage(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	whoAmI(void);
};

#endif
