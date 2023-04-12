/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/12 18:00:37 by jincpark         ###   ########.fr       */
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
		DiamondTrap(const DiamondTrap& d);
		DiamondTrap&	operator=(const DiamondTrap& d);
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
