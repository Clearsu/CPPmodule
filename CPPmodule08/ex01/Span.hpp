/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:43:49 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/27 18:21:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <stdexcept>

class	Span {
	private :
		unsigned int const	maxSize;
		unsigned int 		currSize;
		std::vector<int>	vec;
	public :
		Span();
		Span(unsigned int N);
		Span(Span const & src);
		Span& operator=(Span const & src);
		~Span();

		void			addNumber(int const n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		void	addSequence(std::vector<int>::const_iterator begin, \
				std::vector<int>::const_iterator end);

		class	MaxSizeException : public std::exception {
			public :
				const char * what(void) const throw();
		};
		class	CannotCalculateSpanException : public std::exception {
			public :
				const char * what(void) const throw();
		};
};

#endif
