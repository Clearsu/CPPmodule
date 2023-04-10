/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:20:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 21:14:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	private :
		std::string	ideas[100];
	public :
		// Orthodox Canonical Form
		Brain();
		Brain(const Brain& b);
		Brain&	operator=(const Brain& b);
		~Brain();

		// getter and setter
		const std::string&	getIdea(int index) const;
		void				setIdea(int index, const std::string str);
};

#endif
