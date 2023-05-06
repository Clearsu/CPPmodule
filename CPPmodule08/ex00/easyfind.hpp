/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:02:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/06 16:07:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>

template<typename T>
bool	easyfind(const T& container, const int n)
{
	/*
	while (iter != end) {
		if (*iter == n)
			return true;
		++iter;
	}
	return false;
	*/
	if (find(container.begin(), container.end(), n) != container.end())
		return true;
	return false;
}

#endif
