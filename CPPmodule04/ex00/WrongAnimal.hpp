/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:38:04 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/08 16:31:43 by jincpark         ###   ########.fr       */
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
		virtual ~WrongAnimal();

		// getter
		const std::string&	getType(void) const;

		// setter
		void	setType(const std::string type);

		// no subtype polymorphism
		void	makeSound(void);
};

#endif
