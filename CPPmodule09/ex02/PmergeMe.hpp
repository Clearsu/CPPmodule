/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:43:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/05/01 15:04:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGE_ME__
#define __PMERGE_ME__

#include <vector>

class	PmergeMe {
	private :
		static PmergeMe*	instance;

		std::vector<int>	vec_src;
		std::vector<int>	vec_dest;

		PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		void	parseArgv(int argc, char** argv);
		void	mergeInsertionSort(std::vector<int>::iterator start,
				std::vector<int>::iterator finish);
		void	insertionSortVector(std::vector<int>::iterator start,
				std::vector<int>::iterator finish);
	public :
		static PmergeMe*	getInstance(int argc, char** argv);
		static void			deleteInstance(void);

		void	sort(void);
		void	printVector(void);
};

#endif
