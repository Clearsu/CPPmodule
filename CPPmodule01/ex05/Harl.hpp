/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:56:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/18 17:35:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl {
	private :
		std::string	levelStr[4];
		void		(Harl::*func[4])(void);
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
	public :
		Harl();
		void	complain(std::string level);
};

#endif
