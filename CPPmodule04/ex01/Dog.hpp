/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:10:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 15:20:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public :
		// Orthodox Canonical Form
		Dog();
		Dog(const Dog& d);
		Dog&	operator=(const Dog& d);
		~Dog();

		// overriding
		void	makeSound(void);
};

#endif
