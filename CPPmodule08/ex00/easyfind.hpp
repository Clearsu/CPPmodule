/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:02:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/25 14:04:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <vector>
#include <stdexcept>

/*
class	NoSuchValueException : public std::exception
{
	public :
		const char*	what(void) const throw()
		{
			return "No such value";
		}
};

template<typename T>
std::size_t	easyfind(const std::vector<T>& v, int n) throw (std::exception)
{
	std::size_t	size = v.size();

	for (std::size_t i = 0; i < size; i++)
		if (v[i] == n)
			return i;
	throw NoSuchValueException();
}
*/

template<typename T>
std::vetor<T>::iterator&	easyfind(const std::vector<T>& v, int n) throw (std::exception)
{
	return v.find(n);
}

#endif
