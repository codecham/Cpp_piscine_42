/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:31:15 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/23 01:37:23 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		virtual ~Brain(void);
		Brain& operator=(const Brain& copy);

		void		setIdea(std::string& idea);
		std::string getIdea(int index) const;

	private:
		int _nb_ideas;
		int	_nb_max_ideas;
		std::string _ideas[100];
};

#endif