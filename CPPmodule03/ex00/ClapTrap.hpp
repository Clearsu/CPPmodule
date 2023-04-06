/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:41:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 21:23:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap {
	private :
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public :
		// OCF
		ClapTrap();
		ClapTrap(const ClapTrap& c);
		ClapTrap&	operator=(const ClapTrap& c);
		~ClapTrap();

		// other constructors
		ClapTrap(const std::string name);
		
		// getter
		const std::string&	getName(void) const;
		unsigned int		getAttackDamage(void) const;

		// setter
		void	setName(const std::string name);
		void	setHitPoints(unsigned int value);
		void	setEnergyPoints(unsigned int value);
		void	setAttackDamage(unsigned int value);

		// actions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
