/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:48:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/17 15:46:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <fstream>

class	Sed {
	private :
		std::string		s1;
		std::string 	s2;
		std::ifstream	infile;
		std::ofstream	outfile;
	public :
		Sed(char **argv);
		~Sed();
		void	doSed(void);
};

#endif
