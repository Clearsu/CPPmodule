/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:10:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/13 17:44:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private :
		Brain	*_brain;
	public :
		// Orthodox Canonical Form
		Dog();
		Dog(const Dog& d);
		Dog&	operator=(const Dog& d);
		~Dog();

		// string constructor
		Dog(const std::string idea);

		// getter
		const Brain&	getBrain(void) const;

		// overriding
		void	makeSound(void) const;
};

#endif
