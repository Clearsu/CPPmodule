/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:41:44 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/23 23:08:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <ostream>

template<typename T>
class	Array
{
	private :
		unsigned int	_size;
		T*				_arr;
	public :
		Array() : _size(0), _arr(NULL) {}
		Array(unsigned int n) : _size(n) {
			if (n == 0) {
				n = 1;
				this->_size = 1;
			}
			try {
				this->_arr = new T[n];
				for (unsigned int i = 0; i < n; i++)
					this->_arr[i] = 0;
			} catch (const std::bad_alloc& ba) {
				std::cerr << "bad alloc caught: " << ba.what() << std::endl;
			}
		}
		Array(const Array& src) {
			this->_size = src._size;
			try {
				this->_arr = new T[src._size];
				for (unsigned int i = 0; i < src._size; i++)
					this->_arr[i] = src._arr[i];
			} catch (const std::bad_alloc& ba) {
				std::cerr << "bad alloc caught: " << ba.what() << std::endl;
			}
		}
		Array&	operator=(const Array& src) {
			if (this == &src)
				return *this;
			this->~Array();
			new (this) Array(src);
			return *this;
		}
		~Array() {
			delete [] this->_arr;
		}

		T&	operator[](const unsigned int idx) const {
			if (idx >= this->_size)
				throw OutOfBoundException();
			return this->_arr[idx];
		}

		class	OutOfBoundException : public std::exception
		{
			const char*	what(void) const throw() {
				return "error: index out of bound";
			}
		};
};

#endif
