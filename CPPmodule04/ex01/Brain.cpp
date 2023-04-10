/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:02:47 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/10 21:14:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Orthodox Canonical Form
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
}

Brain&	Brain::operator=(const Brain& b)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// getter and setter
const std::string&	Brain::getIdea(int index) const
{
	return this->ideas[index];
}

void	Brain::setIdea(int index, const std::string str)
{
	this->idea[index] = idea;
}
