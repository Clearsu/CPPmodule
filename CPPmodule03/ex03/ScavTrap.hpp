/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:13:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 21:10:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private :
		const std::string	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
	public :
		// OCF
		ScavTrap();
		ScavTrap(const ScavTrap& s);
		ScavTrap&	operator=(const ScavTrap& s);
		~ScavTrap();

		// string constructor
		ScavTrap(const std::string name);

		// getter
		const std::string&	getName(void) const;
		unsigned int		getAttackDamage(void) const;

		// actions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate(void);
};

#endif
