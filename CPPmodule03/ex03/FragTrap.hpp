/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:54:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 21:03:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private :
		const std::string	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
	public :
		// OCF
		FragTrap();
		FragTrap(const FragTrap& s);
		FragTrap&	operator=(const FragTrap& s);
		~FragTrap();

		// string constructor
		FragTrap(const std::string name);

		// getter
		const std::string&	getName(void) const;
		unsigned int		getAttackDamage(void) const;

		// actions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);
};

#endif
