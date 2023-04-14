/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/14 13:04:28 by jincpark         ###   ########.fr       */
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
		// OCF
		DiamondTrap();
		DiamondTrap(const DiamondTrap& d);
		DiamondTrap&	operator=(const DiamondTrap& d);
		~DiamondTrap();

		// string constructor
		DiamondTrap(const std::string& name);

		// overloading initializers
		void	initHitPoints(void);
		void	initEnergyPoints(void);
		void	initAttackDamage(void);

		// overloading actions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	whoAmI(void);
};

#endif
