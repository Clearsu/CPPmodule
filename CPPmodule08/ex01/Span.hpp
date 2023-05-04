/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:43:49 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/04 16:07:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <stdexcept>

class	Span {
	private :
		std::vector<int>	vec;
		unsigned int		maxSize;
		unsigned int 		currSize;

		Span();
	public :
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
