/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:41:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/03 21:46:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap {
	private :
		const std::string	_name;
		unsigned int		_hitPoint;
		unsigned int		_energyPoint;
		unsigned int		_attackDamage;
	public :
		ClapTrap();
		ClapTrap(const ClapTrap& c);
		ClapTrap&	operator=(const ClapTrap& c);
		~ClapTrap();

		ClapTrap(const std::string name);

		const std::string&	getName(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
