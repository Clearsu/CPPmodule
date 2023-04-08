/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:38:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 16:07:40 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class	WrongAnimal
{
	protected :
		std::string	type;
	public :
		// Orthodox Canonical Form
		WrongAnimal();
		WrongAnimal(const WrongAnimal& w);
		WrongAnimal&	operator=(const WrongAnimal& w);
		~WrongAnimal();

		// getter
		const std::string&	getType(void) const;

		// setter
		void	setType(const std::string type);

		// no dynamic polymorphism
		void	makeSound(void);
};

#endif
