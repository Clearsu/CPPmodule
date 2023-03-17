/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:48:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/17 12:02:23 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <string>

class	Sed {
	private :
		std::string infile;
		std::string	outfile;
		std::string	s1;
		std::string s2;
	public :
		const std::string	&getInFilename(void);
		const std::string	&getOutFilename(void);
		const std::string	&getS1(void);
		const std::string	&getS2(void);
		void				setInFilename(std::string str);
		void				setOutfilename(std::string str);
		void				setS1(std::string str);
		void				setS2(std::string str);
};

#endif
