/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:13:15 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 22:29:34 by jincpark         ###   ########.fr       */
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

		// actions
		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		void			guardGate(void);
};

#endif
