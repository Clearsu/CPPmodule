/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:20 by jincpark          #+#    #+#             */
/*   Updated: 2023/04/16 22:09:37 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"

// OCF
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	setIdea("no idea");
}

Brain::Brain(const Brain &b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	setIdea(b.getIdea());
}

Brain&	Brain::operator=(const Brain &b)
{
	setIdea(b.getIdea());
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// string constructor
Brain::Brain(const std::string &idea)
{
	std::cout << "Brain string constructor called" << std::endl;
	setIdea(idea);
}

// getter and setter
const std::string&	Brain::getIdea(void) const
{
	return _ideas[0];
}

void	Brain::setIdea(const std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}
