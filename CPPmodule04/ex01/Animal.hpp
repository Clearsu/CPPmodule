/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:17:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 15:25:49 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class	Animal
{
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

		// setter
		void	setType(const std::string& type);

		// member function which children can override
		virtual void	makeSound(void);
};

#endif
