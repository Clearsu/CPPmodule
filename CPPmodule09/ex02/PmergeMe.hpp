/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:43:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/02 22:00:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGE_ME__
#define __PMERGE_ME__

#include <vector>
#include <deque>

#define INSERTION_N 10

class	PmergeMe {
	private :
		static PmergeMe*	instance;

		std::vector<int>	vec;
		std::vector<int>	vec_temp;
		std::deque<int>		deq;
		std::deque<int>		deq_temp;

		PmergeMe();
		PmergeMe(int num);
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		void	checkArgc(int argc, char** argv);
		void	parseArgv(int argc, char** argv);

		void	mergeInsertionSortVector(int left, int right);
		void	insertionSortVector(int left, int right);
		void	mergeVector(int left, int mid, int right);

		void	mergeInsertionSortDeque(int left, int right);
		void	insertionSortDeque(int left, int right);
		void	mergeDeque(int left, int mid, int right);

	public :
		static PmergeMe*	getInstance(int num);
		static PmergeMe*	getInstance(int argc, char** argv);
		static void			deleteInstance(void);
		
		void	sortVector(void);
		void	sortDeque(void);

		static std::time_t	getCurrentTimeMicrosec(void);	
		void				printVector(const char* str, const char* color) const;

		std::size_t	getVectorSize(void) const;
		std::size_t	getDequeSize(void) const;
		
		void	isSorted(void) const;
};

#endif
