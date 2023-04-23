/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:27:43 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/23 17:12:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T&	min(const T& a, const T& b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
const T&	max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif
