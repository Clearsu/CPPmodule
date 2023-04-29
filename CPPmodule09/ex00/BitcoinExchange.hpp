/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:00:52 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/30 00:28:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <map>

class	BitcoinExchange {
	private :
		static BitcoinExchange*	btc;
		
		std::map<long, double> db;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		~BitcoinExchange();

	public :
		static BitcoinExchange*	getInstance(void);
		static void				deleteInstance(void);
		void					exchange(char** argv);
};

#endif
