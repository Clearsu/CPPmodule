/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:17:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 22:14:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

# include "Brain.hpp"

class	Animal
{
	private :
		Brain*	brain;
	protected :
		std::string	type;
	public :
		// orthodox canonical form
		Animal();
		Animal(const Animal& a);
		Animal&	operator=(const Animal &a);
		virtual ~Animal();

		// getter
		const std::string	&getType(void) const;
		const Brain*		getBrainPtr(void) const;

		// setter
		void	setType(const std::string& type);
		void	setBrain(const std::string& idea);

		// member function which children can override
		virtual void	makeSound(void) const;
};

#endif
