/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:41:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/06 20:48:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap {
	private :
		const std::string	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
	public :
		// OCF
		ClapTrap();
		ClapTrap(const ClapTrap& c);
		ClapTrap&	operator=(const ClapTrap& c);
		virtual ~ClapTrap();

		// other constructors
		ClapTrap(const std::string name);
		
		// getter
		virtual const std::string&	getName(void) const;
		unsigned int				getHitPoints(void) const;
		virtual unsigned int		getAttackDamage(void) const;

		// actions
		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
};

#endif
