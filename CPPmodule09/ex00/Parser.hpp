/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:19:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 00:33:23 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <string>

class	Parser {
	private :
		Parser();
		Parser(const Parser& src);
		Parser& operator=(const Parser& src);
		~Parser();

		static long		getLastDayOfMonth(long year, long month);
	public :
		static bool		checkCsvFormat(const std::string& line);
		static long		parseDate(const std::string& line);
		static double	parsePrice(const std::string& line);
		static void		checkInputFormat(const std::string& line);
		static float	parseCount(const std::string& line);
};

#endif
