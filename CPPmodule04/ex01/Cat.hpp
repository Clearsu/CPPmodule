/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:40:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 21:57:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private :
		Brain*	_brain;
	public :
		// Orthodox Canonical Form
		Cat();
		Cat(const Cat& c);
		Cat&	operator=(const Cat& c);
		~Cat();

		// overriding
		void	makeSound(void) const;
};

#endif
