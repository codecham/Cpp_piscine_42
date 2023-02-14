/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:52:15 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 04:15:07 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

Brain::Brain()
{
	std::cout << CYAN << "Constructor of Brain called" << RESET << std::endl;
	_nb_ideas = 100;
}

Brain::Brain(const Brain& copy)
{
	int i;

	i = 0;
	std::cout << CYAN << "Constructor by copy of Brain called" << RESET << std::endl;
	while (i < copy._nb_ideas)
	{
		_ideas[i] = copy._ideas[i];
		i++;
	}
}

Brain::~Brain(void)
{
	std::cout << CYAN << "Destructor of Brain called" << RESET << std::endl;
}

Brain&	Brain::operator=(const Brain& copy)
{
	int i;

	i = 0;
	std::cout << CYAN << "Operator = of Brain called" << RESET << std::endl;
	if (this != &copy)
	{
		while (i < copy._nb_ideas)
		{
			this->_ideas[i] = copy._ideas[i];
			i++;
		}
	}
	return(*this);
}

void		Brain::setIdea(std::string& idea, int index)
{
	if (index > 0 && index < _nb_ideas)
		_ideas[index] = idea;
	else
		std::cout << "setIdea's index is out of range." << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	if (index > 0 && index < _nb_ideas)
		return(_ideas[index]);
	else
	{
		std::cout << "getIdea's index is out of range." << std::endl;
		return(0);
	}
}

