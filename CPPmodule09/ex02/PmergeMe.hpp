/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:43:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/03 14:47:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGE_ME__
#define __PMERGE_ME__

#include <vector>
#include <deque>

#include <sys/time.h>

#define INSERTION_N 10

template <typename Container>
class	PmergeMe {
	private :
		Container	cont;
		Container	contTemp;

		PmergeMe() {}
		PmergeMe(const PmergeMe& src) { (void)src; }
		PmergeMe<Container>& operator=(const PmergeMe<Container>& src) { (void)src; return *this; }

		void	checkArgc(int argc, char** argv) {
			std::size_t	count;
			std::size_t	maxInt;
		
			if (argc == 1)
				throw std::runtime_error("Error: no argument");
			count = 0;
			maxInt = static_cast<std::size_t>(std::numeric_limits<int>::max());
			while (*(argv++)) {
				++count;
				if (count > maxInt) {
					throw std::runtime_error("Error: too many arguments");
				}
			}
		}

		void	parseArgv(int argc, char** argv) {
			char*		endptr = 0;
			long		value;
		
			for (int i = 1; i < argc; ++i) {
				value = std::strtol(argv[i], &endptr, 10);
				if (value <= 0 || value != static_cast<int>(value) 
						|| *endptr != '\0' || errno == ERANGE) {
					throw std::runtime_error("Error: bad argument: " + std::string(argv[i]));
				}
				this->cont.push_back(static_cast<int>(value));
			}
		}

		typedef typename Container::iterator iter;
		typedef typename Container::const_iterator const_iter;
		void	mergeInsertionSort(iter left, iter right) {
			iter	mid;
		
			if (right - left < INSERTION_N) {
				insertionSort(left, right);
				return ;
			}
			mid = left + (right - left) / 2;
			mergeInsertionSort(left, mid);
			mergeInsertionSort(mid + 1, right);
			merge(left, mid, right);
		}

		void	insertionSort(iter left, iter right) {
			iter	outer_it;
			iter	inner_it;
			int		key;
		
			for (outer_it = left + 1; outer_it <= right; ++outer_it) {
				key = *outer_it;
				inner_it = outer_it - 1;
				while (inner_it >= left && *inner_it > key) {
					*(inner_it + 1) = *inner_it;
					if (inner_it == this->cont.begin())
						break ;
					--inner_it;
				}
				if (inner_it == this->cont.begin())
					*inner_it = key;
				else
					*(inner_it + 1) = key;
			}
		}

		void	merge(iter left, iter mid, iter right) {
			iter	left_it;
			iter	right_it;
			iter	recopy_it;
			iter	temp_it;
		
			left_it = left;
			right_it = mid + 1;
		
			while (left_it <= mid && right_it <= right) {
				if (*left_it < *right_it)
					this->contTemp.push_back(*(left_it++));
				else
					this->contTemp.push_back(*(right_it++));
			}
		
			while (left_it <= mid)
				this->contTemp.push_back(*(left_it++));
		
			while (right_it <= right)
				this->contTemp.push_back(*(right_it++));
		
			temp_it = this->contTemp.begin();
			for (recopy_it = left; recopy_it <= right; ++recopy_it)
				*recopy_it = *(temp_it++);
		
			this->contTemp.clear();
		}

	public :
		PmergeMe(int num) {
			int	randval;
	
			std::srand(std::time(NULL));
			for (int i = 0; i < num; ++i) {
				randval = std::rand();
				this->cont.push_back(randval);
			}
		}
		PmergeMe(int argc, char** argv) {
			checkArgc(argc, argv);
			parseArgv(argc, argv);
		}
		~PmergeMe() {}

		void	sort(void) {
			mergeInsertionSort(this->cont.begin(), this->cont.end() - 1);
		}

		std::time_t	getCurrentTimeMicrosec(void) {
			struct timeval	currentTime;
		
			gettimeofday(&currentTime, NULL);
			return currentTime.tv_sec * 1000000UL + currentTime.tv_usec;
		}


		void		print(const char* str, const char* color) const {
			const_iter it_end = this->cont.end();
		
			std::cout << color << str;
			for (const_iter it = this->cont.begin(); it < it_end; ++it) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}

		std::size_t	getSize(void) const {
			return this->cont.size();
		}

		void	isSorted(void) const {
			const_iter it = this->cont.begin();
			const_iter it_end = this->cont.end() - 1;
		
			if (this->cont.size() == 1)
				return ;
			while (it < it_end) {
				if (*it > *(it + 1))
					throw std::runtime_error("Error: unsorted");
				++it;
			}
		}
};

#endif
