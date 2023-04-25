/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:21:58 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/25 16:01:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>

typedef struct sData
{
	int	data;
}	Data;

class Serializer
{
	private :
		Serializer();
		Serializer(const Serializer& src);
		Serializer&	operator=(const Serializer& src);
		~Serializer();
	public :
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
