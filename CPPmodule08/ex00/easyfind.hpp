/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:02:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/25 17:03:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

template<typename T>
bool	easyfind(const T& container, int n)
{
	typename T::const_iterator iter = container.begin();
	typename T::const_iterator end = container.end();

	while (iter != end) {
		if (*iter == n)
			return true;
		++iter;
	}
	return false;
}

#endif
