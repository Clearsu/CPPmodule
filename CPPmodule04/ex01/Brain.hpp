/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 22:09:40 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	private :
		std::string	_ideas[100];
	public :
		// OCF
		Brain();
		Brain(const Brain &b);
		Brain&	operator=(const Brain &b);
		~Brain();

		// string constructor
		Brain(const std::string &idea);

		// getter and setter
		const std::string&	getIdea(void) const;
		void				setIdea(const std::string idea);
};

#endif
