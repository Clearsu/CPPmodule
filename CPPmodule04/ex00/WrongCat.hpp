/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:32:23 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 16:32:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public :
		// Orthodox Canonical Form
		WrongCat();
		WrongCat(const WrongCat& w);
		WrongCat&	operator=(const WrongCat& w);
		~WrongCat();

		// no subtype polymorphism
		void	makeSound(void);
};

#endif
