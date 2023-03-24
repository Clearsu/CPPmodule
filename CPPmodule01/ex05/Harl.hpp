/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:56:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/24 20:39:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl {
	private :
		std::string	levelStr[4];
		void		(Harl::*func[4])(void);

		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
	public :
		Harl();
		void	complain(std::string level);
};

#endif
